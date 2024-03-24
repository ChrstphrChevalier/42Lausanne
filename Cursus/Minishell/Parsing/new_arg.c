/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:02:12 by waziz             #+#    #+#             */
/*   Updated: 2024/03/21 10:56:50 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui refait un tableau en divisant les arguments  par $
// Gère aussi le cas pour $?
static void make_new_tab(char **arg_more, char **new, char *tmp, int more, int t)
{
    int     i;
    char    *tmp;

    tmp = ft_strdup(arg_more[t]);
    free(new[more]);
    if (!tmp)
        return(error_zero(2));
    i = 0;
    while (tmp[i])
    {
        i = 0;
        if (tmp[i] == '$')
            i++;
        while (tmp[i] != '$' && tmp[i] != '?' && tmp[i] != '\0')
            i++;
        if (tmp[i] == '?')
            i++;
        if (i > 0)
            new[more++] = ft_substr(tmp, 0, i);
        if (tmp[i])
            tmp = tmp + i;
    }
    free(tmp);
}
// Fonction qui check la présence de dollars dans une string.
static int  check_sdollars(char *s)
{
    int i;
    int dollars;

    i = 0;
    dollars = 0;
    while (s[i])
    {
        if (s[i] == '$')
            return (1);
        i++;
    }
    return (0);
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

    more = check_tabdollars(arg_more) + 1;
    i = tablen(arg_more) + 1;
    new = malloc((more + i) * sizeof(char *));
    if (!new)
        return (error_zero(2));
    t = 0;
    more = 0;
    while (arg_more[t])
    {
        new[more] = ft_strdup(arg_more[t]);
        if (arg_more[t][0] != 39 && check_sdollars(arg_more[t]));
            make_new_tab(arg_more, new, tmp, more, t);
        if (arg_more[t][0] == 39)
            more++;
        t++;
    }
    free_tab(arg_more);
    arg_more = new;
}

// Fonction maîtresse qui appel les autres afin de convertir l'argument si nécéssaire..
// ..et de concaténé les resultat pour retrouver un seul et même argument.
void    replace_argument(char **argument, t_export *alloctrack)
{
    int     t;
    int     erase;
    char    **arg_more;

    t = 0;
    while (argument[t])
    {
        arg_more = alloc_tab(argument[t]);
        quote_parse(argument[t], arg_more, 0);
        dollars_parse(arg_more, 0);
        free(argument[t]);
        argument[t] = convert_n_concat(arg_more, alloctrack);
        if (!argument[t])
        {
            erase = t;
            t -= 1;
            while (++t <= tablen(argument))
                argument[t] = argument[t + 1];
            t = erase - 1;
        }
        t++;
    }
}
