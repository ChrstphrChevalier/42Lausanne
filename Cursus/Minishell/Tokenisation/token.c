/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:43:49 by waziz             #+#    #+#             */
/*   Updated: 2024/03/24 09:37:32 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int input_quote(t_parse *info)
{
    int i;

    i = 0;
    while (info->input[i])
    {
        if (info->input[i] == '"')
        {
            i++;
            while (info->input[i] != '"')
                i++;
            if (info->input[i] == '\0')
                info->quote += 1;
            else
                info->quote += 2;
        }
        if (info->input[i] == 39)
        {
            i++;
            while (info->input[i] != 39)
                i++;
            if (info->input[i] == '\0')
                info->quote += 1;
            else
                info->quote += 2;
        }
        i++;
    }
    return (quote);
}