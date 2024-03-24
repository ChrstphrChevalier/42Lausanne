/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_a&b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:19:12 by waziz             #+#    #+#             */
/*   Updated: 2024/03/21 11:31:59 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui alloue de la mémoire à un tableau à deux dimensions..
// ..pour y insérer tous les noms de fichiers présent dans le répertoire actuel..
// ..et ensuite le retourner.
char **all_files()
{
    DIR             *count;
    DIR             *opn;
    struct dirent   *files_found;
    char            **files_names;
    int             i;

    i = 0;
    if ((opn = opendir(".")) == NULL || (count = opendir(".")) == NULL)
        return (error_zero(1));
    while ((files_found = readdir(count)) != NULL)
        i++;
    closedir(count);
    files_names = malloc((i + 1) * sizeof(char *));
    if (!files_names)
        return (error_zero(2));
    i = 0;
    while ((files_found = readdir(opn)) != NULL)
        files_names[i++] = ft_strdup(files_found->d_name);
    files_names[i] = NULL;
    closedir(opn);
    return (files_names);
}

// garde les chaines correspondante a notre recherche et ecrase les autres.
static void final_filter_b(char **filter_b, char *tmp, int skip)
{
    int i;
    int t;

    i = 0;
    while (filter_b[i])
    {
        if (ft_strncmp(filter_b[i], tmp, skip) == 0)
            i++;
        else
        {
            t = i;
            free(filter_b[i]);
            while (filter_b[t + 1])
            {
                filter_b[t] = filter_b[t + 1];
                t++;
            }
            filter_b[t] = NULL;
        }
    }
}

// Fonction qui filtre tous les noms de fichier par le debut du noms de fichier..
// .. ex : fichier* tous les fichiers qui commencent par fichier seront dans le tableau..
// ..retourné. les autres se font supprimé par écrasement.
char **filter_b(char *input)
{
    char    **filter_b;
    char    *tmp;
    int     quote;
    int     skip;

    filter_b = all_files();
    if (!filter_b)
        return (NULL);
    skip_quote_b(input, skip, quote);
    if (quote > 0)
        erase_quote_b(input, tmp);
    final_filter_b(filter_b, tmp, skip);
    free(tmp);
    return (filter_b);
}

// garde les chaines correspondante a notre recherche et ecrase les autres.
static void final_filter_a(char **filter_a, char *tmp, int skip)
{
    int i;
    int t;
    int mem;

    t = -1;
    while (filter_a[++t])
    {
        i = skip;
        while (tmp[ft_strlen(tmp) - skip] == filter_a[t][ft_strlen(filter_a[t]) - skip] && skip > 0)
            skip--;
        if (skip != 0)
        {
            mem = t;
            free(filter_a[t]);
            while (filter_a[t + 1])
            {
                filter_a[t] = filter_a[t + 1];
                t++;
            }
            filter_a[t] = NULL;
            t = mem;
        }
        skip = i;
    }
}

// Fonction qui filtre tous les noms de fichier par la fin du noms de fichier..
// .. ex : *.c tous les fichiers qui finissent par .c seront dans le tableau..
// ..retourné. les autres se font supprimé par écrasement.
// Le premier * est recherche en prenant soin de skip les " et ' s'il yen a 2.
char **filter_a(char *input)
{
    char    **filter_a;
    char    *tmp;
    int     quote;
    int     skip;

    filter_a = all_files();
    if (!filter_a)
        return (NULL);
    skip_quote_a(input, skip, quote);
    if (quote > 0)
        erase_quote_a(input, tmp);
    final_filter(filter_a, tmp, skip);
    free(tmp);
    return (filter_a);
}
