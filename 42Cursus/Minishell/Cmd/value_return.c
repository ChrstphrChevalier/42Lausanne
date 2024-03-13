/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:38:35 by waziz             #+#    #+#             */
/*   Updated: 2024/02/29 15:39:34 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui affiche la valeur de la dernière commande retourné.
int    last_return(int status)
{
    int w;

    if (status == 42)
    {
        printf("No commands have been previously entered.\n");
        return (0);
    }
    w = write(STDOUT_FILENO, "mnsh : Value of last command is : ", 34);
    if (w < 34)
        return (error_zero(7));
    ft_putnbr_fd(status, STDOUT_FILENO);
    w = write (STDOUT_FILENO, "\n", 1);
    if (w < 1)
        return (error_zero(7));
    return (1);
}