/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:44 by amery             #+#    #+#             */
/*   Updated: 2023/03/20 19:00:37 by amery            ###   ########.fr       */
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

//SORT
void	sort(t_tab ab, char **list);
void	choice_fun(t_tab ab, char *cmd);
//FUNCTION
void	swap(t_tab ab, char *cmd);
void	push(t_tab ab, char *cmd);
void	rotate(t_tab ab, char *cmd);
//PS_CREATE_TAB
int		*create_a(char **tab, int s);
int		*create_b(int s);
int		free_tab(t_tab ab);
//PS_VERIF
char	**ft_julien(t_tab *ab, char **arg);
int		ps_verif(char **a, int size);
int		checkdouble(t_tab ab);
int		free_julien(char **arg);
//CHECKER
char	**checker(char **list);
int		free_list(char **list);

#endif