/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:29:32 by waziz             #+#    #+#             */
/*   Updated: 2024/03/10 14:19:57 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int    check_echo(t_token *tokens)
{
    int i;
    int j;

    i = 0;
    if (strncmp(tokens->cmd, "echo", 4) == 0)
    {
        while (tokens->argument[i])
        {
            j = ft_strlen(tokens->argument[i]) - 1;
            if (tokens->argument[i][0] == '$')
            {
                if (!dollars(tokens->argument[i] + 1, 1))
                    i++;
            }
            else if (tokens->argument[i][0] == '"')
            {
                write(STDOUT_FILENO, tokens->argument[i] + 1, j);
                i++;
            }
            else
                echo(token->argument[i++]);
        }
        return(1);
    }
    return (0);
}
static int    check_echon(t_token *tokens)
{
    int i;
    int j;

    i = 0;
    if (strncmp(tokens->cmd, "echo -n", 7) == 0)
    {
        while (tokens->argument[i])
        {
            j = ft_strlen(tokens->argument[i]) - 2;
            if (tokens->argument[i][0] == '$')
            {
                if (!dollars(tokens->argument[i] + 1, 1))
                    i++;
            }
            else if (tokens->argument[i][0] == '"')
            {
                write(STDOUT_FILENO, tokens->argument[i] + 1, j);
                i++;
            }
            else
                echon(token->argument[i++]);
        }
        return(1);
    }
    return (0);
}

static int checks(t_token *tokens)
{
    if (strncmp(tokens->cmd, "$", 1) == 0 && strncmp(tokens->cmd + 1, "?", 1) != 0)
    {
        if (!dollars(tokens->cmd + 1, 0))
            return (0);
    }
    if (strncmp(tokens->cmd, "$", 1) == 0 && strncmp(tokens->cmd + 1, "?", 1) == 0)
    {
        if (!dollars(tokens->cmd + 1, 0))
            return (0);
    }
    if (strncmp(tokens->cmd, "cd", 2) == 0 && tokens->argument[1] == NULL)
        cd(tokens->argument[0]);
    if (strncmp(tokens->cmd, "pwd", 3) == 0)
    {
         if (tokens->argument != NULL)
            {
                printf("mnsh : No argument with -pwd- .\n");
                return (0);
            }
        pwd();
    }
    if (strncmp(tokens->cmd, "exit", 4) == 0)
        ft_exit();
    return (1);
}
static int check_environ(t_token *tokens, t_export *alloctrack)
{
    int i;

    i = 0;
    if (strncmp(tokens->cmd, "export", 6) == 0)
    {
        while (argument[i])
            export(tokens->argument[i++], alloctrack);
    }
    if (strncmp(tokens->cmd, "unset", 5) == 0)
    {
        while (argument[i])
            ft_unset(tokens->argument[i++], alloctrack);
    }
    if (strncmp(tokens->cmd, "env", 3) == 0)
    {
        if (tokens->argument != NULL)
            {
                printf("mnsh : No argument with -env- .\n");
                return (0);
            }
        ft_env();
    }
    return (1);
}