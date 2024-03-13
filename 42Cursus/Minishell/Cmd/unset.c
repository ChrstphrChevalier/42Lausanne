/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:26:44 by waziz             #+#    #+#             */
/*   Updated: 2024/03/01 13:26:15 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui supprime la variable d'environnement trouvée en l'écrasant avec la suivante du tableau.
static void delete_var(char **environ, char *var_name, char *tmp, int i)
{
    tmp = environ[i];
    while (environ[i])
    {
        environ[i] = environ[i + 1];
        i++;
    }
}
// Fonction qui check si la variable qu'on veut supprimé est alloué par nos soins..
// ..si c'est la cas on ecrase le pointeur.
static void check_alloc(t_export *alloctrack, char *var_name, int j)
{
    int i;
    int tmp;

    i = 0;
    while(alloctrack->ptr_tab[i])
    {
        tmp = i;
        if (strncmp(alloctrack->ptr_tab[i], var_name, j) == 0)
        {
            while(alloctrack->ptr_tab[i])
                alloctrack->ptr_tab[i] = alloctrack->ptr_tab[i + 1];
            i = tmp;
        }
        i++;
    }
}

// Fonction qui supprime une variable du tableau d'environnement.
// Si elle n'est pas trouvée on affiche une erreur.
// On free le pointeur si la variable est trouvée.
int    ft_unset(const char *var_name, t_export *alloctrack)
{
    int     i;
    int     j;
    int     found;
    char    *tmp;

    i = -1;
    j = ft_strlen(var_name);
    found = 0;
    while (environ[++i])
    {
        if (ft_strncmp(environ[i], var_name, j) == 0)
        {
            delete_var(environ, var_name, tmp, i);
            check_alloc(alloctrack, var_name, j);
            free(tmp);
            found = 1;
        }
    }
    if (!found)
    {
        printf("mnsh : Variable : %s not found.\n", var_name);
        return (0);
    }
    printf("mnsh : Variable %s deleted successfully.\n", var_name);
    return (1);
}
