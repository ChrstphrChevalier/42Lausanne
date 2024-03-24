/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:28:46 by waziz             #+#    #+#             */
/*   Updated: 2024/03/01 13:24:37 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// "echo"
// Ecriture de l'argument donné dans la commande terminal dans la sortie de celui-ci
// write car si STDOUT est redirigé dans un fichier, ca ecrira contrairement à printf
// Gestion de l'erreur si tout ne s'est pas écrit entièrement
int    echo(char *input)
{
    size_t  len;
    ssize_t w;

    len = ft_strlen(input);
    w = write (STDOUT_FILENO, input, len);
    if (w < len)
        return (error_zero(7));
    return (1);
}
// "echo -n"
// Pareil qu'au dessus mais les "\n" sont tronqué.
// Gestion de l'erreur si tout ne s'est pas écrit entièrement
int    echon(char *input)
{
    ssize_t i;
    ssize_t w;

    i = ft_strlen(input);
    if (input[i] == '\n')
    {
        i = 0;
        while (input[i] != '\n')
        {
            w = write(STDOUT_FILENO, &input[i], 1);
            if (w < 1)
                return (error_zero(7));
            i++;
        }
    }
    else
    {
        w = write(STDOUT_FILENO, input, i);
        if (w < i)
            return (error_zero(7));
    }
    return (1);
}

// "echo < fichier.txt"
// affiche le contenu d'un fichier dans son entrièreté dans la sortie du terminal.
// Gestion de l'erreur si tout ne s'est pas écrit entièrement
int    echo_input_file()
{
    char        buffer[1024];
    ssize_t     r;
    ssize_t     w;

    r = read(STDIN_FILENO, buffer, 1024);
    if (r < 0)
        return (error_zero(6));
    if (r == 0)
    {
        w = write(STDOUT_FILENO, "\n", 1);
        if (w < 1)
            return (error_zero(7));
        return (NULL);
    }
    w = write(STDOUT_FILENO, buffer, ft_strlen(buffer));
    if (w < 0)
        return (error_zero(7));
    return (1);
}
