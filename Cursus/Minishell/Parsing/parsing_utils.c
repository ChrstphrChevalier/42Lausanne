/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:53:47 by waziz             #+#    #+#             */
/*   Updated: 2024/03/21 11:12:15 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui vérifie la présence de wildcard à traiter non compris..
// ..entre " et '.
int check_wildcard(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == '*')
            return (1);
        if (s[i] == 39)
        {
            i++;
            while (s[i] != 39)
                i++;
        }
        if (s[i] == '"')
        {
            i++;
            while (s[i] != '"')
                i++;
        }
        i++;
    }
    return (0);
}
