/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 08:29:40 by waziz             #+#    #+#             */
/*   Updated: 2024/03/16 10:26:02 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    check_echo(t_token *tokens)
{
    int i;

    i = 0;
    if ((strncmp(tokens->cmd, "echo", 4) == 0 && tokens->cmd[4] == '\0'))
    {
        while (tokens->argument[i])
        {
            if ()
        }
    }
}