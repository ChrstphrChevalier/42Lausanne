/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:26:39 by waziz             #+#    #+#             */
/*   Updated: 2024/03/10 11:54:11 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui libère la mémoire de chaque chaine de caractere d'un char **
// Puis libère la mémoire du tableau.
void    free_tab(char **entries)
{
    int i;

    i = 0;
    if (entries)
    {
        while (entries[i])
            free(entries[i++]);
        free(entries);
    }
}

// Fonction qui libère la mémoire alloué pour la structue t_export et ce qu'elle contient
void    free_at(t_export *alloctrack)
{
    int i;

    if (alloctrack)
    {
        if (!alloctrack->ptr_tab)
            free(alloctrack);
        else
        {
            i = 0;
            while (i < alloctrack->count_ptr)
                free(alloctrack->ptr_tab[i++]);
            free(alloctrack);
        }
    }
}