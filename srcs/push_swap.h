/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:44 by amery             #+#    #+#             */
/*   Updated: 2023/03/21 11:25:09 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "utils/push_swap_utils.h"
# include <stdlib.h>

typedef struct s_tab
{
	int	*a;
	int	*b;
	int	*c;
	int	*d;
	int	sa;
	int	*psa;
	int	sb;
	int	*psb;
	int	sc;
	int	sd;
}		t_tab;

typedef struct s_fun
{
	void	(*swap)(t_tab, char*);
	void	(*push)(t_tab, char*);
	void	(*rotate)(t_tab, char*);
	void	(*current)(t_tab, char*);
}			t_fun;

typedef struct s_g
{
	int	i;
	int	j;
	int	grp[100][1000];
	int	s1;
	int	s2;
	int	subgrp[500];
	int	s3;
}	t_g;

//SORT
void	sort(t_tab ab);
void	choice_fun(t_tab ab, void (*f)(t_tab, char *), char *cmd);
//UNDERSORT
void	atob(t_tab ab, t_g g);
void	sort_a(t_tab ab, t_g g);
void	btoa(t_tab ab, t_g g);
//UNDERSORT_2
void	sort_three(t_tab ab);
void	sort_five(t_tab ab, t_g g);
//FUNCTION
void	swap(t_tab ab, char *cmd);
void	push(t_tab ab, char *cmd);
void	rotate(t_tab ab, char *cmd);
//PS_CREATE_TAB
void	create_group(int *tab, int s, t_g *g);
void	create_subgroup(int *tab, int s, t_g *g);
int		*create_a(char **tab, int s);
int		*create_b(int s);
int		free_tab(t_tab ab);
//PS_UTILS
int		get_nsmallest(int *tab, int n, int size);
int		get_id(int *tab, int size, int n);
int		check_group(int *tab, int size, int *n, int nsize);
int		get_biggest_in_range(int *tab, int size, int range);
//PS_UTILS_2
int		is_three_sort(t_tab ab);
//PS_VERIF
char	**ft_julien(t_tab *ab, char **arg);
int		free_julien(char **arg);
int		ps_verif(char **a, int size);
int		checkdouble(t_tab ab, t_g g);

#endif