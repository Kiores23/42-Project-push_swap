/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:32 by amery             #+#    #+#             */
/*   Updated: 2023/03/16 18:38:03 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_biggest_in_range(int *tab, int size, int range)
{
	int	r;
	int	i;

	i = -1;
	r = tab[0];
	while (++i < range / 2 + 1)
	{
		if (tab[i] > r)
			r = tab[i];
	}
	i = -1;
	while (++i < range / 2 + 1)
	{
		if (tab[size - i - 1] > r)
			r = tab[size - i - 1];
	}
	return (r);
}

int	get_id(int *tab, int size, int n)
{
	int	i;

	i = 0;
	while (tab[i] != n && i < size)
		i++;
	if (tab[i] != n)
		return (-1);
	return (i);
}

int	check_group(int *tab, int size, int *n, int nsize)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (get_id(n, nsize, tab[i]) >= 0)
			return (1);
		i++;
	}
	return (0);
}

static int	gt_nsmlst_nxt(int *tab, int n, int size, int it1)
{
	int	it2;
	int	i;

	i = it1;
	while (n-- > 1)
	{
		it1 = i;
		it2 = -1;
		while (++it2 < size && i == it1)
		{
			if (tab[it2] > tab[it1])
				i = it2;
		}
		--it2;
		while (++it2 < size)
		{
			if (tab[it2] < tab[i] && tab[it2] > tab[it1])
				i = it2;
		}
	}
	return (tab[i]);
}

int	get_nsmallest(int *tab, int n, int size)
{
	int	it1;
	int	it2;

	it1 = 0;
	it2 = -1;
	while (++it2 < size)
	{
		if (tab[it2] < tab[it1])
			it1 = it2;
	}
	if (n == 1)
		return (tab[it1]);
	return (gt_nsmlst_nxt(tab, n, size, it1));
}
