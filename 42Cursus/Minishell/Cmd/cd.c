/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 07:47:03 by waziz             #+#    #+#             */
/*   Updated: 2024/02/25 14:41:57 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// "cd avec uniquement un chemin relatif ou absolu"
// chdir prend uniquement des chemins relatif ou absolu et nous y emmene automatiquement.
// gestion de l'erreur si le chemin donné n'est pas valide.
int cd(char *path)
{
    if (chdir(path) == -1)
        return (error_zero(8));
    return (1);
}