/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:33:12 by waziz             #+#    #+#             */
/*   Updated: 2024/03/13 12:04:13 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui filtre les noms de fichiers en fonction du début et de la fin du nom..
// ..de fichier. ex : fichier*.c, tous les noms commencant par fichier et terminant par..
// .. .c seront dans le tableau retourné.
static char **filter_ab(char *input)
{
    char    **filter_ab;
    char    **fb;
    int     i;
    int     j;

    i = 0;
    j = 0;
    filter_ab = filter_a(input);
    fb = filter_b(input);
    while (input[j] != '*')
        j++;
    while (filter_ab[i])
    {
        if (ft_strncmp(fb[0], filter_ab[i], j) == 0)
            i++;
        else
        {
            free(filter_ab[i]);
            filter_ab[i] = filter_ab[i + 1];
        }
        i++;
    }
    free_filter(fb);
    return (filter_ab);
}

// Fonction qui gère la demande utilisateur en fonction de l'input.
static char    **filter_simple(char *input)
{
    char    **filter;
    int     i;
    int     j;
    int     k;

    i = 0;
    j = 0;
    k = 0;
    while (input[i] != '*')
        i++;
    k = i;
    while (input[k] == '*')
        k++;
    while (input[k +j])
        j++;
    if (i > 0 && j == 0)
        filter = filter_b(input);
    if (i == 0 && j > 0)
        filter = filter_a(input);
    if (i == 0 && j == 0)
        filter = all_files();
    if (i > 0 && j > 0)
        filter = filter_ab(input);
    return (filter);
}

// Fonction qui détermine s'il y a plus ou moins d'un wildcard.
static int  init_check(char *input)
{
    int i;
    int check;
    
    i = 0;
    check = 1;
    while (input[i] != '*')
        i++;
    while (input[i] == '*')
        i++;
    while (input[i])
    {
        if (input[i] == '*')
            check++;
        i++;
    }
    return (check);
}

// Fonction qui applique une commande à tous les noms de fichiers demandé..
char    **wilcards(char *input)
{
    char    **filter;
    char    *ignore;
    int     i;
    int     check;

    i = -1;
    check = init_check(input);
    if (check > 1)
        filter = filter_more(input);
    else
        filter = filter_simple(input);
    return (filter);
}
