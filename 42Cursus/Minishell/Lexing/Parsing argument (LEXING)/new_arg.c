/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:02:12 by waziz             #+#    #+#             */
/*   Updated: 2024/03/13 15:46:22 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui refait un tableau en divisant les arguments  $
static void make_new_tab(char **arg_more, char **new, char *tmp, int more, int t)
{
    int     i;
    char    *tmp;

    tmp = ft_strdup(arg_more[t]);
    if (!tmp)
        return(error_zero(2));
    i = 0;
    while (tmp[i])
    {
        if (tmp[i] == '$')
            i++;
        while (tmp[i] != '$' && tmp[i] != '\0')
            i++;
        if (i > 0)
            new[more++] = ft_substr(tmp, 0, i);
        tmp = tmp + i + 1;
    }
    free(tmp);
}
// Fonction qui gere l'allocation de mémoire nécéssaire pour le nouveau tableau
// Free l'ancien tableau et le fait pointer vers le nouveau.
// Conserve les arguments tels qu'ils sont si pas ils commencent par '
static void  dollars_parse(char **arg_more, int t)
{
    int     i;
    int     more;
    int     t;
    char    **new;

    more = check_dollars(arg_more);
    i = tablen(arg_more) + 1;
    new = malloc((more + i) * sizeof(char *));
    if (!new)
        return (error_zero(2));
    t = 0;
    more = 0;
    while (arg_more[t])
    {
        new[more] = arg_more[t];
        if (arg_more[t][0] != 39)
            make_new_tab(arg_more, new, tmp, more, t);
        if (arg_more[t][0] == 39)
            more++;
        t++;
    }
    free_tab(arg_more);
    arg_more = new;
}
// Fonction qui mesure la taille d'un tableau à deux dimensions.
static int  tablen(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}
// Fonction maîtresse qui appel les autres afin de convertir l'argument si nécéssaire..
// ..et de concaténé les resultat pour retrouver un seul et même argument.
void    replace_argument(t_token *tokens)
{
    int     t;
    int     erase;
    char    **arg_more;

    t = 0;
    while (tokens->argument[t])
    {
        arg_more = alloc_tab(tokens->argument[t]);
        squote_parse(tokens->argument[t], arg_more, 0);
        dollars_parse(arg_more, 0);
        free(tokens->argument[t]);
        tokens->argument[t] = convert_n_concat(arg_more);
        if (!tokens->argument[t])
        {
            erase = t;
            t -= 1;
            while (++t <= tablen(tokens->argument))
                tokens->argument[t] = tokens->argument[t + 1];
            t = erase - 1;
        }
        t++;
    }
}
