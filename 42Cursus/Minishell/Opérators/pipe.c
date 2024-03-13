/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:43:40 by waziz             #+#    #+#             */
/*   Updated: 2024/03/01 15:23:30 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_pipe(int fd_out, int fd_in)
{
    int pipefd[2];

    if (pipe(pipefd) == -1)
        return (erroro_zero(12));
    if (dup2(pipefd[0], fd_out) == -1)
        return (error_zero(4));
    if (dup2(pipefd[1], fd_in) == -1)
        return (error_zero(4));
    return (1);
}