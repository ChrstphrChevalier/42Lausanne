/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 08:26:12 by waziz             #+#    #+#             */
/*   Updated: 2024/03/19 14:20:13 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction créée car + de 25 lignes
// on free l'ancien tableau argument et ses chaines de caracteres.
// puis nous lui attribuons un nouveau tableau en le faisant pointé dessus.
static void final_step_cw(char **argument, char **new_argument, int i)
{
    free_tab(argument);
    new_argument[i] = NULL;
    argument = new_argument;
}

// Fonction qui fais un nouveau tableau en mettant les noms de fichiers désiré
// s'ils sont trouvé dans le tableau argument à l'endroit ou ils doivent être.
static int  convert_wildcard(char **argument, int t)
{
    char    **w;
    char    **new_argument;
    int     i;
    int     j;

    w = wildcards(argument[i]);
    if (!w)
        return (0);
    new_argument = malloc((tablen(argument) + tablen(w) + 1) * sizeof(char *));
    if (!new_argument)
        return (error_zero(2));
    i = -1;
    while (++i < t)
        new_argument[i] = ft_strdup(argument[i]);
    i = t;
    j = -1;
    while (w[++j])
        new_argument[i++] =  ft_strdup(w[j]);
    free_tab(w);
    j = t + 1;
    t = i;
    while (argument[j])
        new_argument[i++] = ft_strdup(argument[j++]);
    final_step_cw(argument, new_argument, i);
    return (1);
}

// Fonction qui traduis les * si nécéssaire.
// Ou qui écrase les " et les ' s'il n'ya pas de * à traiter.
int  ft_parsing(char **argument, t_export *alloctrack)
{
    int     t;
    char    **final_argument;

    replace_argument(argument, alloctrack);
    t = 0;
    while (argument[t])
    {
        if (check_wildcard(argument[t]))
            if (!convert_wildcard(argument, t))
                return (0);
        else
            if (!erase_quote(argument[t]))
                return (0);
        t++;
    }
    return (1);
}
