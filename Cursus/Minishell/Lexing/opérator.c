/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opérator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:21:21 by waziz             #+#    #+#             */
/*   Updated: 2024/03/20 10:05:14 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static int single_operator(t_token *tokens)
{
    if (strncmp(tokens->operator, '<', 1) == 0 && tokens->operator[1] == '\0')
    {
        if (!redirect_input(tokens->arg_operator))
            return (0);
        return (1);
    }
    if (strncmp(tokens->operator, '>', 1) == 0 && tokens->operator[1] == '\0')
    {
        if (!redirect_output(tokens->arg_operator))
            return (0);
        return (1);
    }
    return (1);
}
static int  double_operator(t_token *tokens)
{
    if (strncmp(tokens->operator, ">>", 2) == 0 && tokens->operator[2] == '\0')
    {
        if (!redirect_stdout_append(tokens->arg_operator))
            return (0);
        return (1);
    }
    if (strncmp(tokens->operator, "<<", 2) == 0 && tokens->operator[2] == '\0')
    {
        if (!redirect_input_command(tokens->arg_operator))
            return (0);
        return (1);
    }
    if (!tokens->operator)
        return (1);
    return (0);
}

int chose_opertaor(t_token *tokens)
{
    if (!single_operator(tokens))
        return (0);
    if (!double_operator(tokens))
        return (0);
    return (1);
}