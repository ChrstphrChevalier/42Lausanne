/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:06:44 by waziz             #+#    #+#             */
/*   Updated: 2024/02/28 11:04:38 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui gère l'initialisation de la structure t_export déclaré dans le .h
// Cette structure vise à pointé vers les zones mémoires allouer dans le tableau environ
// Environ étant un tableau systeme gere la mémoire de ce qu'il alloue, ce que nous allouons est à notre charge
// Tous les éléments pointeur du tableau pointe sur NULL par sécurité
// count_ptr sera notre index pour notre tableau
// not_environ identifie si nous avons du créer le tableau environ ou non
struct t_export *init(t_export *alloctrack)
{
    int t;

    alloctrack = malloc(sizeof(t_export));
    if (!alloctrack)
    {
        perror("mnsh : Allocating memory failed.\n");
        return (NULL);
    }
    alloctrack->ptr_tab = malloc(1000 * sizeof(char *));
    if (!alloctrack->ptr_tab)
    {
        perror("mnsh : Allocating memory failed.\n");
        free(alloctrack);
        return (NULL);
    }
    t = 0;
    while (t < 1000)
        alloctrack->ptr_tab[t++] = NULL;
    alloctrack->count_ptr = 0;
    alloctrack->not_environ = 0;
    alloctrack->status = 42;
    return (alloctrack);
}

// Fonction qui libère la mémoire en fonction du déroulement du programme.
void    free_export(t_export *alloctrack, char **environ)
{
    if (alloctrack->not_environ == 0)
        free_at(alloctrack);
    if (alloctrack->not_environ == 1)
    {
        free_at(alloctrack);
        free_tab(environ);
    }
}