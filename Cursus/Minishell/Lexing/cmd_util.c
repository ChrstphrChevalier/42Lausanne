/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:28:28 by waziz             #+#    #+#             */
/*   Updated: 2024/03/20 10:30:33 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui gère l'appel de la commande echo tel que défini
// dans le vrai terminal
int make_echo(t_token *tokens)
{
    int t;

    if (strncmp(tokens->cmd, "echo", 4) == 0
        && tokens->cmd[4] == '\0')
    {
        t = 0;
        if (!tokens->argument[t])
            return (1);
        while (tokens->argument[t])
            if (!echo(tokens->argument[t++]))
                return (0);
        return (1);
    }
    return (0);
}

// Fonction qui gère l'appel de la commande echo -n tel que défini
// dans le vrai terminal
int make_echon(t_token *tokens)
{
    int t;

    if (strncmp(tokens->cmd, "echo -n", 7) == 0
        && tokens->cmd[7] == '\0')
    {
        t = 0;
        if (!tokens->argument[t])
            return (1);
        while (tokens->argument[t])
            if (!echon(tokens->argument[t++]))
                return (0);
        return (1);
    }
    return (0);
}
// Fonction qui gère l'appel de la commande cd tel que défini
// dans le vrai terminal
int make_cd(t_token *tokens)
{
    if (strncmp(tokens->cmd, "cd", 2) == 0
        && tokens->cmd[2] == '\0')
    {
        if (!tokens->argument[0])
        {
            printf("mnsh : cd : Only with relative or absolute path");
            return (1);
        }
        if (tokens->argument[1])
        {
            printf("mnsh : cd : String not in pwd : %s", tokens->argument[0]);
            return (1);
        }
        if (!cd(tokens->argument[0]))
            return (0);
        return (1);
    }
    return (0);
}
// Fonction qui gère l'appel de la commande pwd tel que défini
// dans le vrai terminal
int make_pwd(t_token *tokens)
{
    if (strncmp(tokens->cmd, "pwd", 3) == 0
        && tokens->cmd[3] == '\0')
    {
        if (tokens->argument[0])
        {
            printf("mnsh : pwd : Too many argument");
            return (1);
        }
        if (!pwd())
            return (0);
        return (1);
    }
    return (0);
}
// Fonction qui gère l'appel de la commande export tel que défini
// dans le vrai terminal
int make_export(t_token *tokens, t_export *alloctrack)
{
    int t;

    if (strncmp(tokens->cmd, "export", 6) == 0
        && tokens->cmd[6] == '\0')
    {
        if (!tokens->argument[0])
        {
            if (!ft_env())
                return (0);
            return (1);
        }
        t = 0;
        while (tokens->argument[t])
            if (!export(tokens->argument[t++], alloctrack))
                return (0);
        return (1);
    }
    return (0);
}