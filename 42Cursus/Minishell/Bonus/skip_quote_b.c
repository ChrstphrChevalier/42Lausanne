/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_quote_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:00:23 by waziz             #+#    #+#             */
/*   Updated: 2024/03/15 13:44:48 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui écrase les " par paire.
static void dquote(char *tmp, int i, int j)
{
    j = i;
    while (tmp[j])
    {
        tmp[j] = tmp[j + 1];
        j++;
    }
    while (tmp[i] != '"')
        i++
    j = i + 1;
    while (tmp[j])
    {
        tmp[j] = tmp[j + 1];
        j++;
    }
}
// Fonction qui ecrase les ' par paire.
static void squote(char *tmp, int i, int j)
{
    j = i;
    while (tmp[j])
    {
        tmp[j] = tmp[j + 1];
        j++;
    }
    while (tmp[i] != 39)
        i++
    j = i + 1;
    while (tmp[j])
    {
        tmp[j] = tmp[j + 1];
        j++;
    }
}

// Fonction qui écrase les " ou les ' par paire.
void    erase_quote_b(char *input, char *tmp)
{
    int     i;
    int     j;

    tmp = ft_strdup(input);
    i = 0;
    while (tmp[i] != '*')
    {
        if (tmp[i] == '"')
            dquote(tmp, i, j);
        if (tmp[i] == 39)
            squote(tmp, i, j);
        i++;
    }
}
// Fonction qui ignore les * compris entre " ou '.
void    skip_quote_b(char *input, int skip_b, int quote)
{
    skip_b = 0;
    quote = 0;
    while (input[skip_b] != '*' && input[j])
    {
        if (input[skip_b] == 39)
        {
            skip_b++;
            while (input[skip_b] != 39)
                skip_b++;
            skip_b++;
            quote += 2;
        }
        if (input[skip_b] == '"')
        {
            skip_b++;
            while (input[skip_b] != '"')
                skip_b++;
            skip_b++;
            quote += 2;
        }
        skip_b++;
    }
    skip_b++;
    skip_b -= quote;
}
