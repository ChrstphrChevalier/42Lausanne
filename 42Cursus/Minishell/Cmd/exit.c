/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:07:25 by waziz             #+#    #+#             */
/*   Updated: 2024/02/29 14:24:25 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// "Exit sans option"
// Fonction qui sert à arrêter les programme proprement.
void    ft_exit()
{
    printf("mnsh : Exiting ...\n");
    exit (1);
}