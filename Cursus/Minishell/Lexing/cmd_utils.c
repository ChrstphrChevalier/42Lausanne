/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:54:49 by waziz             #+#    #+#             */
/*   Updated: 2024/03/20 10:37:26 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui gère l'appel de la commande unset tel que défini
// dans le vrai terminal
int make_unset(t_token *tokens, t_export *alloctrack)
{
    int t;

    if (strncmp(tokens->cmd, "unset", 5) == 0
        && tokens->cmd[5] == '\0')
    {
        if (!tokens->argument[0])
        {
            printf("mnsh : unset : Not enough arguments");
            return (1);
        }
        t = 0;
        while (tokens->argument[t])
            if (!ft_unset(tokens->argument[t++], alloctrack))
                return (0);
        return (1);
    }
    return (0);
}
// Fonction qui gère l'appel de la commande env tel que défini
// dans le vrai terminal
int make_env(t_token *tokens)
{
    if (strncmp(tokens->cmd, "env", 3) == 0
        && tokens->cmd[3] == '\0')
    {
        if (tokens->argument[0])
        {
            printf("mnsh : env -> %s : No such file or directory", tokens->argument[0]);
            return (1);
        }
        if (!ft_env())
            return (0);
        return (1);
    }
    return (0);
}
// Fonction qui gère l'appel de la commande exit tel que défini
// dans le vrai terminal
int make_exit(t_token *tokens)
{
    if (strncmp(tokens->cmd, "exit", 4) == 0
        && tokens->cmd[4] == '\0')
    {
        ft_exit();
        return (1);
    }
    return (0);
}

int make_exec(t_token *tokens)
{
    if (tokens->cmd[0] == '/'
        || (tokens->cmd[0] == '.' && tokens->cmd[1] == '/'))
    {
        if (!exec(tokens->cmd, tokens->argument))
            return (0);
        return (1);
    }
    return (0);
}