/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_arg_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:08:10 by waziz             #+#    #+#             */
/*   Updated: 2024/03/13 15:28:02 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui compte le nombre de '
// et qui renvoi le resultat divisé par 2 car il vont en paire.
static int  yessquote(char *arg)
{
    int i;
    int squote;

    i = 0;
    while (arg[i])
    {
        if (arg[i] == 39)
            squote++;
        i++;
    }
    return (squote / 2);
}

// Fonction qui alloue de la mémoire pour le tableau qui recevra..
// ..la chaîne divisé en plusieurs chaîne à partir de chaque paire de  ' ou "..
// ..j'ai ajouté 2 au malloc si jamais il y a une chaine avant le..
// ..premier ' et pour la chaine NULL de fin.
char  **alloc_tab(char *arg)
{
    int     i;
    int     squote;
    char    **arg_more;

    i = -1;
    squote = yessquote(arg);
    arg_more = malloc((squote + 2) * sizeof(char *));
    if (!arg_more)
        return (error_null(1));
    i = 0;
    while (i < squote + 2)
        arg_more[i++] = NULL;
    return (arg_more);
}

// Fonction qui détermine si on prend la chaine en double ou en single quote.
static void quote_incrément(char *tmp, int i)
{
    if (tmp[i] == 39 || tmp[i] == '"')
        i++;
    if (tmp[0] == 39)
        while (tmp[i] != 39)
            i++;
    else if (tmp[0] == '"')
        while (tmp[i] != '"')
            i++;
    else
        while (tmp[i] != 39 || tmp[i] != '"' || tmp[i] != '\0')
            i++;
    if ((tmp[i + 1] == 39 || tmp[i + 1] == '"') && (tmp[0] == 39 || tmp[0] == '"'))
        i++;
}

// Fonction qui divise la chaine en plusieur si présence de '
// Le tout est stocker dans arg_more.
void    squote_parse(char *arg, char **arg_more, int t)
{
    int     i;
    char    *tmp;

    tmp = ft_strdup(arg);
    if (!tmp)
        return(error_zero(2));
    while (tmp[i])
    {
        i = 0;
        quote_incrément(tmp, i);
        if (i > 0)
            arg_more[t++] = ft_substr(tmp, 0, i);
        if (tmp[i + 1] == '\0')
            break;
        else
            tmp = tmp + i + 1;
    }
    arg_more[t] = NULL;
    free(tmp);
}

