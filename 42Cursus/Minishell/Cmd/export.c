/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:27:01 by waziz             #+#    #+#             */
/*   Updated: 2024/02/25 20:01:00 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui modifie une variable deja existante si elle est trouvée.
// On alloue de la mémoire pour la nouvelle variable, on free l'ancienne..
//..puis on fait pointé le pointeur du tableau envrion vers la nouvelle variable.
// On collecte le pointeur également dans Alloctrack pour pouvoir free en fin de programme.
static int ft_found(char **environ,char *v_env, int i, int j, int found, t_export *alloctrack)
{
    if (strncmp(environ[j], v_env, i) == 0)
    {
        free(environ[j]);
        environ[j] = ft_strdup(v_env);
        if(!environ[j])
            return (error_zero(2));
        alloctrack->ptr_tab[alloctrack->count_ptr] = environ[j];
        alloctrack->count_ptr++;
        found = 1;
    }
    return (1);
}

// Fonction qui ajoute une variable d'environnement au tableau deja existant.
// On alloue de la mémoire pour un nouveau tableau, récupère les anciens pointeurs..
// ..puis on ajoute le nouveau pointeur de la nouvelle variable.
// On collecte le pointeur également dans Alloctrack pour pouvoir free en fin de programme.
static int  ft_notfound(char **environ,char *v_env, int j, int k, int found, t_export *alloctrack)
{
    char **new_environ;
    int t;

    t = -1;
    if (environ[j] == NULL && found == 0)
    {
        new_environ = malloc((k + 2) * sizeof(char *));
        if (!new_environ)
            return (error_zero(2));
        while (environ[++t])
            new_environ[t] = environ[t];
        new_environ[j] = ft_strdup(v_env);
        if (!new_environ[j])
            return (error_zero(2));
        alloctrack->ptr_tab[alloctrack->count_ptr] = new_environ[j];
        alloctrack->count_ptr++;
        new_environ[j + 1] = NULL;
        free_tab(environ);
        environ = new_environ;
        j++;
    }
    return (1);
}
// Fonction qui crée et alloue de la mémoire pour le tableau environ censé contenir les.. 
// ..variables d'environnement. 
static int  not_environ(char **environ, char *v_env, t_export *alloctrack)
{
    if (environ == NULL)
    {
        environ = malloc(2 * sizeof(char *));
        if (!environ)
            return (error_zero(2));
        environ[0] = ft_strdup(v_env);
        if (!environ[0])
            return (error_zero(2));
        environ[1] = NULL;
        alloctrack->not_environ = 1;
    }
    return (1);
}
// Fonction qui calcul la taille d'un tableau à 2 dimensions
static int tablen(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}
// "export sans option"
// Fonction qui ajoute ou remplace une variable d'environnement existante.
// Et si le tableau environ n'est pas initialisé par le systeme nous lui en créons un.
int export(char *v_env, t_export *alloctrack)
{
    int i;
    int j;
    int k;
    int found;

    i = 0;
    j = 0;
    found = 0;
    k = tablen(environ);
    while (v_env[i] != '=')
        i++;
    if (v_env[i] == '\0')
        return (0);
    while (environ[j])
    {
        if (!ft_found(environ, v_env, i, j, found, alloctrack))
            return (-1);
        j++;
        if (!ft_notfound(environ, v_env, j, k, found, alloctrack))
            return (-1);
    }
    if (!not_environ(environ, v_env, alloctrack))
        return (-1);
    return (1);
}
