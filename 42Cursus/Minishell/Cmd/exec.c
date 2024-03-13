/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:24:01 by waziz             #+#    #+#             */
/*   Updated: 2024/03/06 14:03:42 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int exec(char *exec, char **arg)
{
    pid_t   children;

    children = fork();
    if (children == -1)
        return (error_zero(10));
    if (children == 0)
    {
        if (execve(exec, arg, NULL) == -1)
            return (error_zero(11));
    }
    return (1);
}