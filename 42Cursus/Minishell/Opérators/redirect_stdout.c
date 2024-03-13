/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdout.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:45:49 by waziz             #+#    #+#             */
/*   Updated: 2024/02/27 22:22:12 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// (>>)
// Fonction qui redirige la sortie du terminal dans un fichier..
// ..mais qui n'ecrase pas son contenu.
int  redirect_stdout_append(const char *fichier)
{
    int fd;

    fd = open(fichier, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1)
        return (error_zero(3));
    if (dup2(fd, STDOUT_FILENO) == -1)
        return (error_zero(4));
    if (close(fd) == -1)
        return (error_zero(5));
    return (1);
}  