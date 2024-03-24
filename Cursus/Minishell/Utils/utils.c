/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:36:36 by waziz             #+#    #+#             */
/*   Updated: 2024/03/19 10:55:31 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui mesure la taille d'un tableau à deux dimensions.
int  tablen(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}

// Fonction qui compte les nombres total de caractères présente dans toutes les chaines..
// ..du tableau.
int  tab_slen(char **tab)
{
    int i;
    int t;
    int slen;

    t = 0;
    while (tab[t])
    {
        i = 0;
        while (tab[t][i++])
            slen++;
        t++;
    }
    return (slen);
}