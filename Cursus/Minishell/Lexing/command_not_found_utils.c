/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_not_found_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 07:52:37 by waziz             #+#    #+#             */
/*   Updated: 2024/03/19 14:34:50 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Condition parsing echo et echo -n
int    error_echo(char *cmd)
{
    if (strncmp(cmd, "echo", 4) == 0 && cmd[4] != '\0')
    {
        if (strncmp(cmd, "echo -n", 7) == 0 && cmd[7] == '\0')
            return (1);
        else
        {
            printf("mnsh : command not found : %s", cmd);
            return (0);
        }
    }
}
// Condition parsing cd
int    error_cd(char *cmd)
{
    if (strncmp(cmd, "cd", 2) == 0 && cmd[2] != '\0')
    {
        printf("mnsh : command not found : %s", cmd);
        return (0);
    }
    return (1);
}
// Condition parsing pwd
int    error_pwd(char *cmd)
{
    if (strncmp(cmd, "pwd", 3) == 0 && cmd[3] != '\0')
    {
        printf("mnsh : command not found : %s", cmd);
        return (0);
    }
    return (1);
}

int    error_export_unset_env(char *cmd)
{
    // Condition parsing export
    if (strncmp(cmd, "export", 6) == 0 && cmd[6] != '\0')
    {
        printf("mnsh : command not found : %s", cmd);
        return (0);
    }
    // Condition parsing unset
    if (strncmp(cmd, "unset", 5) == 0 && cmd[5] != '\0')
    {
        printf("mnsh : command not found : %s", cmd);
        return (0);
    }
    // Condition parsing env
    if (strncmp(cmd, "env", 3) == 0 && cmd[3] != '\0')
    {
        printf("mnsh : command not found : %s", cmd);
        return (0);
    }
    return (1);
}
// Condition parsing exit
int    error_exit(char *cmd)
{
    if (strncmp(cmd, "exit", 4) == 0 && cmd[4] != '\0')
    {
        printf("mnsh : command not found : %s", cmd);
        return (0);
    }
    return (1);
}
