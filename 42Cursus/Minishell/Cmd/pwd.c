/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:12:34 by waziz             #+#    #+#             */
/*   Updated: 2024/02/29 14:24:25 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui affiche le chemin absolu jusqu'au répértoire actuel.
int pwd()
{
    char    *cwd;
    ssize_t len;
    ssize_t w;

    cwd = getcwd(NULL, 0);
    if (cwd == NULL)
        return (error_zero(9));
    len = ft_strlen(cwd);
    w = write(STDOUT_FILENO, cwd, len);
    if (w < len)
    {
        free(cwd);
        return (error_zero(7));
    }
    free(cwd);
    return (1);
}
