/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_quote_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:25:07 by waziz             #+#    #+#             */
/*   Updated: 2024/03/21 11:31:59 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui ecrase les " par paire.
static void dquote(char *tmp, int i)
{
    int j;

    j = i;
    while (tmp[j])
    {
        tmp[j] = tmp[j + 1];
        j++;
    }
    while (tmp[i] != '"')
        i--;
    j = i;
    while (tmp[j])
    {
        tmp[j] = tmp[j + 1];
        j++;
    }
}

// Fonction qui ecrase les ' par paire.
static void squote(char *tmp, int i)
{
    int j;

    j = i;
    while (tmp[j])
    {
        tmp[j] = tmp[j + 1];
        j++;
    }
    while (tmp[i] != 39)
        i--;
    j = i;
    while (tmp[j])
    {
        tmp[j] = tmp[j + 1];
        j++;
    }
}

// Fonction qui écrase les " ou les ' par paire.
void    erase_quote_a(char *input, char *tmp)
{
    int     i;

    i = ft_strlen(input);
    tmp = ft_strdup(input);
    while (tmp[i] != '*')
    {
        if (tmp[i] == 39)
            squote(tmp, i);
        if (tmp[i] == '"')
            dquote(tmp, i);
        i--;
    }
}

// Fonction qui skip les " ou les ' par paire si rencontré.
static void skipping(char *input, int i, int quote)
{
    if (input[i] == 39)
    {
        i--;
        while (input[i] != 39)
            i--;
        quote += 2;
    }
    if (input[i] == '"')
    {
        i--;
        while (input[i] != '"')
            i--;
        quote += 2;
    }
}

// Fonction qui ignore les * compris entre " ou '.
void    skip_quote_a(char *input, int skip_a, int quote)
{
    int i;

    i = ft_strlen(input);
    quote = 0;
    while (input[i] != '*' && i >= 0)
    {
        skipping(input, i, quote);
        i--;
    }
    skip_a = 0;
    while (input[i++])
        skip_a++;
    skip_a -= quote;
}
