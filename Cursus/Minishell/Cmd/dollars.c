/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 22:03:47 by waziz             #+#    #+#             */
/*   Updated: 2024/03/10 14:18:33 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int writing(char *vn, char *value, int option)
{
    int w;
    if (option == 1)
    {
        w = write(STDOUT_FILENO, value, ft_strlen(value));
        if (w < ft_strlen(value))
            return (error_zero(7));
    }
    else
        printf("%s", value);
    return (1);
}

// Fonction qui annonce que la variable demandé n'est pas dans le tableau d'environnement.
static int  vnull(char *var_name, int option)
{
    int w;

    if (option == 1)
    {
        w = write(STDOUT_FILENO, "mnsh : Environment variable ", 31);
        if (w < 31)
            return (error_neg(1));
        w = write(STDOUT_FILENO, var_name, ft_strlen(var_name));
        if (w < ft_strlen(var_name))
            return (error_neg(1));
        w = write(STDOUT_FILENO, "is not set.", 11);
        if (w < 12)
            return (error_neg(1));
    }
    else
        printf("mnsh : Environment variable %s is not set.", var_name);
    return (O);
}

// Fonction qui cherche une variable dans le tableau d'environnement et affiche sa valeur..
// ..si elle est trouvée.
int dollars(char *var_name, int option)
{
    char    *value;

    value = getenv(var_name);
    if (value == NULL)
        return (vnull(var_name, option));
    if (!writing(vn, value))
        return (-1);
    return (1);
}
