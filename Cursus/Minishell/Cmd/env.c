/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:49:43 by waziz             #+#    #+#             */
/*   Updated: 2024/02/27 14:06:28 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// "env sans otpion ni arguments"
// Supprime une variable d'environnement dans le tableau environ géré par le système
int    ft_env()
{
    int i;
    ssize_t len;
    ssize_t w;

    i = 0;
    if (!environ)
    {
        printf("mnsh : No environment variables detected.\n");
        return (0);
    }
    while (environ[i])
    {
        len = ft_strlen(environ[i]);
        w = write(STDOUT_FILENO, environ[i], len);
        if (w < len)
            return (error_zero(7));
        i++;
    }
    return (1);
}
