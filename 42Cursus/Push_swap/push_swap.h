/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:02:38 by waziz             #+#    #+#             */
/*   Updated: 2023/12/12 13:20:28 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct stacks_ab
{
	int		*a;
	int		*b;
	char	**stab;
	int		a_len;
	int		b_len;
}	t_stacks;

int		ft_rotate(int *stack, int stack_len);
int		ft_reverse_rotate(int *stack, int stack_len);

void	ft_sa(t_stacks *ab);
void	ft_sb(t_stacks *ab);
void	ft_ss(t_stacks *ab);

void	ft_pa(t_stacks *ab);
void	ft_pb(t_stacks *ab);

void	ft_ra(t_stacks *ab);
void	ft_rb(t_stacks *ab);
void	ft_rr(stacks *ab);

void	ft_rra(t_stacks *ab);
void	ft_rrb(t_stacks *ab);
void	ft_rrr(t_stacks *ab);

int		ft_strlen(const char *str);
size_t	ft_tablen(char **stab);
int		ft_error(void);
int		ft_free(t_stacks *ab, int args);
int		ft_sorted(const int *a, const int a_len);
char	**ft_split(const char *s, char c);

int		ft_init_stacks(t_stacks *ab, char **argv, int args, long int resultat);
void	from_two_to_five(t_stacks *ab);
void	radix_sort(t_stacks *ab);

#endif
