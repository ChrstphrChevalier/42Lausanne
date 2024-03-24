/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:54:52 by waziz             #+#    #+#             */
/*   Updated: 2024/03/19 17:19:04 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction maitresse pour les commandes.
// Si une d'entre elle s'execute elle retourne 1.
int cmd(t_token *tokens, t_export *alloctrack)
{
    if (make_echo(tokens))
        return (1);
    if (make_echon(tokens))
        return(1);
    if (make_cd(tokens))
        return(1);
    if (make_pwd(tokens))
        return(1);
    if (make_export(tokens, alloctrack))
        return(1);
    if (make_unset(tokens, alloctrack))
        return(1);
    if (make_env(tokens))
        return(1);
    if (make_exit(tokens))
        return(1);
    if (make_exec(tokens))
        return (1);
    return (0);
}