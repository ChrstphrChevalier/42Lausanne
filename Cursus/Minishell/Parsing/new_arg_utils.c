/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_arg_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:08:10 by waziz             #+#    #+#             */
/*   Updated: 2024/03/21 10:56:50 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui compte le nombre de '
// et qui renvoi le resultat divisé par 2 car il vont en paire.
// Donc s'il yen à qu'un il renverra 0 car 1 / 2 = 0 en int.
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
    return (squote);
}

// Fonction qui alloue de la mémoire pour le nouveau tableau
// Se nouveau tableau au soit des chaines commencant par un ' et finissant pas 
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
// Sinon l'index est renvoyé juste avant le ' ou le " et s'il yen a pas alors jusqu'au
// caractère nul.
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
    if ((tmp[i] == 39 || tmp[i] == '"') && (tmp[0] == 39 || tmp[0] == '"'))
        i++;;
}

// Fonction qui divise la chaine en plusieur si présence de ' ou de ".
// Le tout est stocker dans arg_more.
void    quote_parse(char *arg, char **arg_more, int t)
{
    int     i;
    char    *tmp;

    tmp = ft_strdup(arg);
    if (!tmp)
        return(error_zero(2));
    i = 0;
    while (tmp[i])
    {
        i = 0;
        quote_incrément(tmp, i);
        if (i > 0 && tmp[i] != '\0')
            arg_more[t++] = ft_substr(tmp, 0, i + 1);
        else
            arg_more[t++] = ft_substr(tmp, 0, i);
        if (tmp[i] == '\0')
            break;
        else
            tmp = tmp + i;
    }
    arg_more[t] = NULL;
    free(tmp);
}

// Fonction qui compte le nombre de dollars présent dans la chaque chaine du tableau donné.
int check_tabdollars(char **arg_more)
{
    int i;
    int t;
    int dollars;

    dollars = 0;
    t = 0;
    while (arg_more[t])
    {
        if (arg_more[t][0] != 39)
        {
            i = 0;
            while (arg_more[t][i])
            {
                if (arg_more[t][i] == '$')
                    dollars++;
                i++;
            }
        }
        t++;
    }
    return (dollars);
}
