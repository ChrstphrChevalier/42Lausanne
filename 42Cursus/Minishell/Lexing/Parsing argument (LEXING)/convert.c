/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:04:31 by waziz             #+#    #+#             */
/*   Updated: 2024/03/13 10:15:12 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui convertit les argument divisé qui comprenne un '$' mais pas de '*'.
static void no_wildcard(char **arg_more, int t)
{
    int     i;
    char    *dollars;
    char    *tmp;
    char    *f;

    if (arg_more[t][0] == '$' && arg_more[t][1] != '\0'
            && !check_wildcard(arg_more[t]))
    {
        i = 0;
        while (arg_more[t][i] != ' ')
            i++;
        dollars = ft_substr(arg_more[t], 0, i);
        free(dollars);
        dollars = dollars_lex(dollars + 1);
        tmp = ft_substr(arg_more[t], i + 1, ft_strlen(arg_more[t]));
        f = arg_more[t];
        arg_more[t] = ft_strcat(dollars, tmp);
        free(f);
        free(tmp);
    }
}

// Fonction qui convertit les arguments divisé qui comprenne '$' et '*'.
static void yes_wildcard(char **arg_more, int t)
{
    int i;
    char    *dollars;
    char    *wildcard;
    char    *f;

    i = 0;
    if (arg_more[t][0] == '$' && arg_more[t][1] == '\0'
            && check_wildcard(arg_more[t]) == 1)
    {
        while (arg_more[t][i] != '*' && arg_more[t][i] != ' ')
            i++;
        dollars = ft_substr(arg_more[t], 0, i);
        free(dollars);
        dollars = dollars_lex(dollars + 1);
        wilcard = ft_substr(arg_more[t], i + 1, ft_strlen(arg_more[t]));
        f = arg_more[t];
        arg_more[t] = ft_strcat(dollars, wildcard);
        free(f);
        free(wildcard);
    }
}

static  void concat(char **arg_more, char *tmp, int t)
{
    ft_strcat(arg_more[0], arg_more[1]);
    tmp = arg_more[1];
    while (arg_more[++t])
        arg_more[t] = arg_more[t + 1];
    free(tmp);
    t = 0;
}

static void check_convert(char **arg_more, int t)
{
    int mem;

    mem = t;
    while (arg_more[t + 1])
    {
        arg_more[t] = arg_more[t + 1];
        t++;
    }
    t = mem - 1;
}

// Fonction qui convertit tous les $ par leur valeur et concaténe toutes les chaines..
// ..pour retrouver notre argument de base convertit.
char    *convert_n_concat(char **arg_more)
{
    int     t;
    char    *tmp;
    char    *cc;

    t = 0;
    while (arg_more[t])
    {
        no_wildcard(arg_more, t);
        yes_wildcard(arg_more, t);
        if (!arg_more[t])
            check_convert(arg_more, t);
        t++;
    }
    if (!arg_more[0])
    {
        free_tab(arg_more);
        return (NULL);
    }
    t = 0;
    while (arg_more[t + 1])
        concat(arg_more, tmp, t);
    cc = ft_strdup(arg_more[0]);
    free_tab(arg_more);
    return (cc);
}
