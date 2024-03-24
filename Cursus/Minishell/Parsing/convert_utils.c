/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:18:05 by waziz             #+#    #+#             */
/*   Updated: 2024/03/17 13:55:07 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui cherche une variable dans le tableau d'environnement et..
// ..renvoi un pointeur sur sa valeur si elle est trouvée sinon return NULL.
char *dollars_lex(char *var_name)
{
    char    *value;

    value = getenv(var_name);
    if (value == NULL)
       return (NULL);
    return (value);
}

// Fonction qui check si dst n'est pas null
// Si elle remplie la condition elle incrémente i pour ne pas..
// ..écraser son dernier caractere dans cat et elle free dst.
static void check_dst(char *dst, int i)
{
    if (dst)
    {
        i++;
        free(dst);
    }
}
// Fonction qui concatène src à la fin de dst.
char    *ft_strcat(char *dst, char *src)
{
	int		i;
	int		j;
    char    *cat;

    if (!dst && !src)
        return (NULL);
	i = ft_strlen(dst);
	j = ft_strlen(src);
    cat = malloc((i + j + 1) * sizeof(char));
    if (!cat)
        return (error_null(1));
    i = 0;
    while (dst[i])
    {
        cat[i] = dst[i];
        i++;
    }
    check_dst(dst, i);
    j = 0;
    while (src[j])
        cat[i++] = src[j++];
    cat[i + 1] = '\0';
    return (cat);
}
