/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:05:26 by waziz             #+#    #+#             */
/*   Updated: 2024/03/20 10:05:14 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    lexing(t_token *tokens, t_export *alloctrack)
{
    if (!chose_operator(tokens))
        return (0);
    if (!ft_parsing(tokens->argument, alloctrack))
        return (0);
    if (!command_not_found(tokens->cmd))
        return (0);
    if (!cmd(tokens, alloctrack))
        return (0);
    return (1);
}
