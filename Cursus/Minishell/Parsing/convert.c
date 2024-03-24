/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:04:31 by waziz             #+#    #+#             */
/*   Updated: 2024/03/21 11:07:54 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void choose_convert(char *dollars, t_export *alloctrack)
{
    int i;

    i = 0;
    if (dollars[1] == '?')
        dollars = last_return(alloctrack->status);
    else
        dollars = dollars_lex(dollars + 1);
}

// Fonction qui convertit les argument divisé qui comprenne un '$'
// Puis reconcatène s'il y avait quelque chose après la valeur demandé.
static void convert_dollars(char **arg_more, int t, t_export *alloctrack)
{
    int     i;
    char    *dollars;
    char    *tmp;
    char    *f;

    if (arg_more[t][0] == '$' && arg_more[t][1] != '\0')
    {
        i = 0;
        while (arg_more[t][i] != ' ' && arg_more[t][i] != 39
            && arg_more[t][i] != '"' && arg_more[t][i] != '*'
            && arg_more[t][i] != '?' && arg_more[t][i] != '\0')
            i++;
        if (arg_more[t][i] == '?')
            i++;
        dollars = ft_substr(arg_more[t], 0, i);
        free(dollars);
        choose_convert(dollars, alloctrack);
        tmp = ft_substr(arg_more[t], i, ft_strlen(arg_more[t]));
        f = arg_more[t];
        arg_more[t] = ft_strcat(dollars, tmp);
        free(f);
        free(tmp);
    }
}

// Fonction qui concatène toutes les chaines d'un tableau à deux dimensions en une seule chaine
// Cela nous sert a retrouvé l'argument comme il etait de base avec les $ convertit.
static char *concat(char **arg_more)
{
   int  t;
   int  i;
   int  j;
   int  total_len;
   char *cc;

   total_len = tab_slen(arg_more) + 1;
   cc = malloc(totel_len * sizeof(char));
   if (!cc)
        return (error_null(1));
    t =0;
    i = 0;
    while (arg_more[t])
    {
        j = 0;
        while (arg_more[t][j])
        {
            cc[i++] = arg_more[j++];
            i++;
        }
        t++;
    }
    cc[i] = '\0';
    return (cc);
}

// Fonction qui ecrase la chaine demandé dans le cas ou $ aurait renvoyé null
// Cela se produit lorsque la variable rechercher n'est pas trouvé.
static void erase_convert(char **arg_more, int t)
{
    int mem;

    mem = t;
    while (arg_more[t])
    {
        arg_more[t] = arg_more[t + 1];
        t++;
    }
    t = mem;
}

// Fonction qui convertit tous les $ par leur valeur et concaténe toutes les chaines..
// ..pour retrouver notre argument de base convertit.
char    *convert_n_concat(char **arg_more, t_export *alloctrack)
{
    int     t;
    char    *cc;

    t = 0;
    while (arg_more[t])
    {
        convert_dollars(arg_more, t, alloctrack);
        if (!arg_more[t])
            erase_convert(arg_more, t);
        t++;
    }
    if (!arg_more[0])
    {
        free(arg_more);
        return (NULL);
    }
    cc = ft_strdup(concat(arg_more));
    free_tab(arg_more);
    return (cc);
}
