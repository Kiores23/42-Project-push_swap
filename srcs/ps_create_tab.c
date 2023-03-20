/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:19 by amery             #+#    #+#             */
/*   Updated: 2023/03/20 18:38:54 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_tab(t_tab ab)
{
	if (ab.a)
		free(ab.a);
	if (ab.b)
		free(ab.b);
	return (0);
}

void	create_group(int *tab, int s, t_g *g)
{
	if (s <= 100)
		g->s1 = s / 33 + 2;
	else
		g->s1 = 0.0125 * s + 3.75;
	g->s2 = s / (g->s1);
	g->i = 0;
	while (g->i < g->s1)
	{
		g->j = 0;
		while (g->j < g->s2
			|| (g->i + 1 == g->s1 && g->i * g->s2 + g->j < s))
		{
			g->grp[g->i][g->j] = get_nsmallest(tab, g->i * g->s2 + g->j + 1, s);
			g->j++;
		}
		g->i++;
	}
}

void	create_subgroup(int *tab, int s, t_g *g)
{
	g->s3 = s / 2;
	g->j = -1;
	while (++g->j < g->s3)
		g->subgrp[g->j] = get_nsmallest(tab, g->j + 1, s);
}

int	*create_a(char **tab, int s)
{
	long	tmp;
	int		*a;
	int		i;

	a = malloc(sizeof(int) * s);
	if (!a)
		return (NULL);
	i = -1;
	while (++i < s)
	{
		tmp = ft_atoi(tab[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
		{
			free(a);
			return (NULL);
		}
		a[i] = (int)tmp;
	}
	return (a);
}

int	*create_b(int s)
{
	int	*b;

	b = malloc(sizeof(int) * s);
	if (!b)
		return (NULL);
	ft_bzero(b, s);
	return (b);
}
