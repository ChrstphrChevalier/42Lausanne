/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:38:35 by waziz             #+#    #+#             */
/*   Updated: 2024/03/19 10:55:31 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui affiche la valeur de la dernière commande retourné.
char    *last_return(int status)
{
    char    *state;

    state = ft_itoa(status);
    if (!state)
        return (NULL);
    return (state);
}