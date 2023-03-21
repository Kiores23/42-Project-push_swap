/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:14 by amery             #+#    #+#             */
/*   Updated: 2023/03/21 11:24:49 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_verif(char **a, int size)
{
	int	i;

	i = 0;
	while (i < size && ft_isnumber(a[i]))
		i++;
	if (i < size)
		return (0);
	return (1);
}

int	checkdouble(t_tab ab, t_g g)
{
	g.i = -1;
	if (ab.a[0] == ab.a[1])
		return (0);
	while (++g.i < g.s1)
	{
		g.j = -1;
		while (++g.j + 1 < g.s2
			|| (g.i + 1 == g.s1 && g.s2 * g.i + g.j + 1 < ab.sa))
		{
			if (g.grp[g.i][g.j] == g.grp[g.i][g.j + 1])
				return (0);
		}
	}
	return (1);
}

int	free_julien(char **arg)
{
	int	i;

	i = -1;
	while (arg && arg[++i])
		free(arg[i]);
	if (arg)
		free(arg);
	return (0);
}

char	**ft_julien(t_tab *ab, char **arg)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (arg[0][++i])
	{
		if ((arg[0][i] == ' ' && i && arg[0][i - 1] != ' ')
			|| (!arg[0][i + 1] && arg[0][i] != ' '))
			c++;
	}
	ab->sa = c;
	arg = ft_split(arg[0], ' ');
	return (arg);
}
