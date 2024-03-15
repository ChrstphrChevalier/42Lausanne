/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_mult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:27:02 by waziz             #+#    #+#             */
/*   Updated: 2024/03/15 14:33:50 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction qui renvoi un pointeur à partir de l'occurence chercher dans la chaine.
// Donc si on cherche "on" dans la chaine blablaonblabla, il renverra un pointeur sur 'o'
// Pour qu'il ne soit lisible plus que "onblabla"
static char *ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j] != '\0')
		{
			if (s2[j + 1] == '\0')
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

// Fonction qui check quel filtre de départ on choisit
// Pour n'avoir qu'a chercher les occurences de corps et non plus celle d'extrémités.
static void which_start_filter(char **filter_mult, char *input)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    while (input[i] != '*')
        i++;
    k = ft_strlen(input);
    while (input[k] != '*')
    {
        k--;
        j++;
    }
    if (i > 0 && j == 0)
        filter_mult = filter_b(input);
    if (i == 0 && j > 0)
        filter_mult = filter_a(input);
    if (i == 0 && j == 0)
        filter_mult = all_files();
    if (i > 0 && j > 0)
        filter_mult = filter_ab(input);
}

// Fonction qui écrase le nom de fichier si il ne correspond pas à la recherche utilisateur.
// Gestion du free.
static void crushed(char **filter_mult, char *tmp, int not)
{
    tmp = filter_mult[i];
    while (filter_mult[i])
        filter_mult[i] = filter_mult[i + 1];
    free(tmp);
}

// Fonction qui filtre en fonction de si toute les occurences demandé sont trouvé 
// On recherche toute les occurences chaine par chaine.
// Respect de l'ordre des occurence grace au pointeur "tmp"
// strncmp nous sert à vérifier s'il l'a trouve ou non
// strstr nous sert à checker la nouvelle occurence à partir de l'ancienne pour s'assurer..
//.. qu'on l'a trouve pas avant la précédente (position dans la chaine de caractere)
// not est l'int qui détermine si on à trouvé toute les occurences ou s'il en à manqué..
// Et grâce à lui nous pouvons enfin determiné si nous gardons ou écrasons la string controlé.
static void filtering_mult(char **filter_mult, char **search, char *tmp,int skip_a, int skip_b)
{
    int j;
    int not;

    while (*filter_mult)
    {
        j = 0;
        not = 0;
        tmp = *filter_mult + skip_b;
        while (search[j])
        {
            if (strncmp(tmp, search[j], ft_strlen(tmp) - skip_a) != 0)
                not++;
            if (strncmp(tmp, search[j], ft_strlen(tmp) - skip_a) == 0)
            {
                tmp = ft_strstr(tmp, search[j]);
                tmp = tmp + ft_strlen(search[j]);
            }
            j++;
        }
        if (not == 0)
            *filter_mult++;
        else
            crushed(filter_mult, tmp, not);
    }
    free(search);
}

// Fonction maîtresse qui gere le filtrage
// On choisit notre filtre de départ on fonction des conditions
// On récupère dans tmp l'input à partir du premier '*' puis..
// .. on tronque à partir du dernier '*' pour n'avoir que les occurences de corps
// Skip_a et Skip_b nous servirons dans filtering_mult pour ne pas chercher les occurences..
//.. en début et en fin de chaine s'il y en a. 
//Split "tmp" pour avoir chaque occurence dans une chaine de caractere qui sera contenu dans un **
//Puis on retourne le tableau filtrer.
// Prend en compte les partie entourer de " ou ' et les skip si nécéssaire.
char **filter_more(char *input)
{
    char    **filter_mult;
    char    **search;
    char    *tmp;
    int     skip_a;
    int     skip_b;

    which_start_filter(filter_mult, input);
    skip_quote_a(input, skip_a, skip_b);
    skip_quote_b(input, skip_b);
    tmp = ft_strdup(input + skip_b);
    tmp[skip_a] = '\0';
    search = init_search(tmp);
    free(tmp);
    filtering_mult(filter_mult, search, tmp, skip_a, skip_b);
    return (filter_mult);
}
