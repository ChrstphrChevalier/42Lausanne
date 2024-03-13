/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:28:03 by waziz             #+#    #+#             */
/*   Updated: 2024/03/10 14:18:33 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui affiche le problème rencontré et retourne 0
int error_zero(int num)
{
    if (num == 1)
        perror("mnsh : Error Opendir.\n");
    if (num == 2)
        perror("mnsh : Allocated memory failed.\n");
    if (num == 3)
        perror("mnsh : Openfile.\n");
    if (num == 4)
        perror("mnsh : Redirecting Dup2.\n");
    if (num == 5)
        perror("mnsh : Closing file.\n");
    if (num == 6)
        perror("mnsh : Read Error.\n");
    if (num == 7)
        printf("mnsh : Writing Error.\n");
    if (num == 8)
        perror("mnsh : cd.\n");
    if (num == 9)
        perror("mnsh : pwd.\n");
    if (num == 10)
        perror("mnsh : fork.\n");
    if (num == 11)
        perror("mnsh : execve.\n");
    if (num == 12)
        perror("mnsh : pipe.\n");
    return (0);
}

// Fonction qui affiche le problème rencontré et retourne -1
int  error_neg(int n)
{
    if (n == 1)
        printf("mnsh : Writing Error.\n");
    return (-1);
}

char    *error_null(int n)
{
    if (n == 1)
        perror("mnsh : Allocated memory failed.\n");
    if (n == 2)
        printf("mnsh : Writing Error.\n");
    return (NULL);
}