/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_not_found.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 08:59:35 by waziz             #+#    #+#             */
/*   Updated: 2024/03/19 17:19:04 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int traduct_cmd(char *cmd)
{
    char **tmp;

    tmp = malloc(2 * sizeof(char *));
    if (!tmp)
        return (error_zero(2));
    tmp[0] = ft_strdup(cmd);
    tmp[1] = NULL;
    free(cmd);
    ft_parsing(tmp);
    if (!tmp[0])
        return (0);
    cmd = ft_strdup(tmp[0]);
    free_tab(tmp);
    return (1);
}

// Fonction qui check si dans commande il y a "bonjour" par exemple
// Renvoi une erreur si c'est le cas.
static int other_parse(char *cmd)
{
    if (strncmp(cmd, "echo", 4) != 0 && strncmp(cmd, "cd", 2) != 0
        && strncmp(cmd, "pwd", 3) != 0 && strncmp(cmd, "export", 6) != 0
        && strncmp(cmd, "unset", 5) != 0 && strncmp(cmd, "env", 3) != 0
        && strncmp(cmd, "exit", 4) != 0 && cmd[0] != '\0')
    {
        printf("mnsh : command not found : %s", cmd);
        return (0);
    }
    return (1);
}

// Fonction qui check si la cmd comporte une erreur
// Via les fonctions appelé
// Affiche un message dans le terminal via celle ci
// Return 0 pour indiquer l'erreur ou 1 si la cmd est ok.
int command_not_found(char *cmd)
{
    if (!traduct_cmd(cmd))
        return (0);
    if (!error_echo(cmd))
        return (0);
    else if (!error_cd(cmd))
        return (0);
    else if (!error_pwd(cmd))
        return (0);
    else if (!error_export_unset_env(cmd))
        return (0);
    else if (!error_exit(cmd))
        return (0);
    else if (!other_parse(cmd))
        return (0);
    else if (!cmd[0])
        return (0);
    else
        return (1);
}