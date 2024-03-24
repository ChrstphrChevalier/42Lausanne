/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:39:16 by waziz             #+#    #+#             */
/*   Updated: 2024/03/21 11:12:15 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui écrase le caractère voulu.
// on garde i comme il est car nous somme deja sur l'index voulu.
static void ft_erase(char *erase, int i, int mem)
{
    mem = i;
    while (erase[i])
    {
        erase[i] = erase[i + 1];
        i++;
    }
    i = mem;
}

// Fonction qui écrase les ' voulu.
static void erase_squote(char *erase, i, mem)
{
    ft_erase(erase, i, mem);
    while (erase[i] != 39)
        i++;
    ft_erase(erase, i, mem);
}

// Fonction qui écrase les " voulu.
static void erase_dquote(char *erase, i, mem)
{
    ft_erase(erase, i, mem);
    while (erase[i] != '"')
        i++;
    ft_erase(erase, i, mem);
}

// Fonction qui écrase les " et les ' si nécéssaire.
// on libère la mémoire de l'ancienne 
// pour la refaire pointé sur la nouvelle sans créée de fuite de mémoire.
int erase_quote(char *s)
{
    int     i;
    int     mem;
    char    *erase;

    i = 0;
    erase = ft_strdup(s);
    if (!erase)
        return (error_zero(2));
    while (erase[i])
    {
        if (erase[i] == 39)
            erase_squote(erase, i, mem);
        if (erase[i] == '"')
            erase_dquote(erase, i, mem);
        i++;
    }
    free(s);
    s = erase;
    return (1);
}
