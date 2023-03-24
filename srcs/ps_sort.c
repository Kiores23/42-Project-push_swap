/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:29 by amery             #+#    #+#             */
/*   Updated: 2023/03/24 13:21:08 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choice_fun(t_tab ab, void (*f)(t_tab, char *), char *cmd)
{
	ft_putstr(cmd);
	ft_putchar('\n');
	f(ab, cmd);
	ab.sa = *ab.psa;
	ab.sb = *ab.psb;
}

void	sort(t_tab ab)
{
	t_g		g;

	create_group(ab.a, ab.sa, &g);
	if (ab.sa > 5)
	{
		atob(ab, g);
		sort_a(ab, g);
		g.i = g.s1 - 1;
		btoa(ab, g);
	}
	else if (ab.sa > 3)
		sort_five(ab, g);
	else if (ab.sa == 3)
		sort_three(ab);
	else if (ab.a[0] > ab.a[1])
		choice_fun(ab, &swap, "sa");
}
