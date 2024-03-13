/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:50:02 by waziz             #+#    #+#             */
/*   Updated: 2024/02/27 22:22:12 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui lit l'entrée, l'ajoute à l'historique et agis en fonction des cas.
// Gestion des différentes erreurs possiblement rencontré.
// Libération de la mémoire quand nécéssaire.
static int add_n_print(char **entries, char *input, char *end, int read_bytes, int t)
{
    input = readline("heredoc> ");
    if (input == NULL)
    {
        entries[t++] = ft_strdup(" ");
        add_history("\n");
        free(input);
        if (write (STDOUT_FILENO, "\n", 1) < 1)
            return (error_neg(1));
        return (1);
    }
    add_history(input);
    if (write (STDOUT_FILENO, input, ft_strlen(input)) < ft_strlen(input))
    {
        free(input);
        return (error_neg(1));
    }
    if (ft_strncmp(input, end, ft_strlen(end)) == 0)
    {
        free(input);
        return (0);
    }
    entries[t++] = ft_strdup(input);
    free(input);
    return (1);
}

// Boucle "infini", qui tourne tant que char *end n'est pas entrée ou qu'il n'ya a pas d'erreur.
static int while_one(char **entries, char *input, char *end, int read_bytes, int t)
{
    int check_error;

    while (1)
    {
        check_error = add_n_print(entries, input, end, read_bytes, t);
        if (check_error == -1)
        {
            free_tab(entries);
            return (-1);
        }
        else if (check_error == 0)
            return (0);
    }
}

// Fonction qui écrira chaque entrée une fois la commande appliquée dessus.
static write_entries(char **entries, int t)
{
    int len;

    len = ft_strlen(entries[t]);
    if (write(STDOUT_FILENO, entries[t], len) < len)
    {
        free_tab(entries);
        return(error_neg(1));
    }
}
// (<<)
// Fonction qui applique une commande sur toute les entrées suivante jusqu'à ce que ..
// ..char *end soit entrée.
int    redirect_input_command(void (*f)(char *), char *end)
{
	char    *input;
    int     read_bytes;
    char    **entries;
    int     t;

    t = 0;
    entries = malloc(200 * sizeof(char *));
    if (!entries)
    {
        perror("mnsh : Error allocating memory.");
        free_tab(entries);
        return (0);
    }
    if (while_one(entries, input, end, read_bytes, t) == -1)
        return (0);
    t = -1;
    while (entries[++t])
    {
        (*f)(entries[t]);
        if (write_entries(entries, t) == -1)
            return (0);
    }
    add_history(end);
    free_tab(entries);
    return (1);
}
