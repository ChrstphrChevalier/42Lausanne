/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_quote_middle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:28:39 by waziz             #+#    #+#             */
/*   Updated: 2024/03/21 11:38:35 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// fonction qui créé le tableau parse en faisant un genre de split.
// on garde dans la meme chaine les chaines commencant pas '..
// et le reste dans les autres chaines.
static void squote(char **parse, char *tmp, int i, int w)
{
    w = i;
    if (i > 0)
        parse[t++] = ft_substr(tmp, 0, i);
    while (tmp[i] != 39)
        i++;
    parse[t++] = ft_substr(tmp, w, i + 1);
    i++;
    tmp = tmp + i;
}

// fonction qui créé le tableau parse en faisant un genre de split.
// on garde dans la meme chaine les chaines commencant pas "..
// et le reste dans les autres chaines.
static void dquote(char **parse, char *tmp, int i, int w)
{
    w = i;
    if (i > 0)
        parse[t++] = ft_substr(tmp, 0, i);
    while (tmp[i] != '"')
        i++;
    parse[t++] = ft_substr(tmp, w, i + 1);
    i++;;
    tmp = tmp + i;
}

// Fonction qui créer le nouveau tableau en gardant la place..
// ..et les strings de l'ancien.
// Gestion des frees.
static int  spliter(char **parse, int i, int j, int t)
{
    char    **spliter;
    char    **new_parse;

    spliter = ft_split(parse[t], '*');
    j = tablen(spliter) + 1;
    new_parse = malloc((tablen(parse) + j) * sizeof(char *));
    if (!new_parse)
        return (error_zero(2));
    i = -1;
    while (++i < t)
        new_parse[i] = parse[i];
    i = -1;
    j = t;
    while (spliter[++i])
        new_parse[t++] = spliter[i];
    t++;
    i = t;
    while (parse[j])
        new_parse[t++] = parse[j++];
    new_parse[j] = '\0';
    free_tab(spliter);
    free_tab(parse);
    parse = new_parse;
    t = i;
}

// Fonction qui split toutes les chaines ne commencant pas par..
// .. ' ou " avec pour séparateur le *.
// Ecrase les " et ' de début et fin de chaine s'il yen a.
static void split_wildcard(char **parse)
{
    int     t;
    int     i;
    int     j;

    t = 0;
    while (parse[t])
    {
        i = 0;
        if (parse[t][0] == 39 || parse[t][0] == '"')
        {
            while (parse[t][i])
            {
                parse[t][i] = parse[t][i + 1];
                i++;
            }
            parse[t][i - 1] = '\0';
            t++;
        }
        else
            spliter(parse, i, j, t);
    }
}
// Fonction qui vise à établir un tableau à deux dimension..
// ..contenant tous les arguments à chercher dans le corps du..
// ..nom de fichier.
char    **init_search(char *tmp)
{
    int     i;
    int     t;
    int     w;
    char    **parse;

    i = -1;
    while (tmp[++i])
        if (tmp[i] == '*')
            w++;
    parse = malloc((w + 2) * sizeof(char *));
    if (!parse)
        return (error_null(2));
    i = 0;
    t = 0;
    while (tmp[i])
    {
        if (tmp[i] == 39)
            squote(parse, tmp, i, w);
        if (tmp[i] == '"')
            dquote(parse, tmp, i, w);
        i++;
    }
    split_wildcard(parse);
    return (parse);
}
