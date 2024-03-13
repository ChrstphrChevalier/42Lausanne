/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:19:12 by waziz             #+#    #+#             */
/*   Updated: 2024/03/01 22:48:09 by waziz            ###   ########.fr       */
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

// Fonction qui filtre tous les noms de fichier par le debut du noms de fichier..
// .. ex : fichier* tous les fichiers qui commencent par fichier seront dans le tableau..
// ..retourné. les autres se font supprimé par écrasement.
char **filter_b(char *input)
{
    char    **filter_b;
    int     i;
    int     j;
    int     k;

    filter_b = all_files();
    if (!filter_b)
        return (NULL);
    j = 0;
    while (input[j] != '*')
        j++;
    if (j == 0)
        return (NULL);
    i = 0;
    while (filter_b[i])
    {
        if (ft_strncmp(filter_b[i], input, j) == 0)
            i++;
        k = i - 1;
        free(filter_b[i]);
        while (filter_b[++k])
            filter_b[k] = filter_b[k + 1];
    }
    return (filter_b);
}
// Fonction qui écrase le noms du fichier si il ne correspond pas et free la mémoire allouée.
static void filtering(char **filter, int t)
{
    free(filter[t]);
    filter[t] = filter[t + 1];
}
// Fonction qui filtre tous les noms de fichier par la fin du noms de fichier..
// .. ex : *.c tous les fichiers qui finissent par .c seront dans le tableau..
// ..retourné. les autres se font supprimé par écrasement.
char **filter_a(char *input)
{
    char    **filter_a;
    int     i;
    int     j;
    int     t;

    i = ft_strlen(input);
    j = 0;
    filter_a = all_files();
    if (!filter_a)
        return (NULL);
    while (input[i--] != '*')
        j++;
    t = -1;
    while (filter_a[++t])
    {
        i = j;
        while (input[ft_strlen(input) - j] == filter_a[t][ft_strlen(filter_a[t]) - j] && j > 0)
            j--;
        if (j != 0)
            filtering(filter_a, t);
        j = i;
    }
    return (filter_a);
}
