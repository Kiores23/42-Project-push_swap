/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_undersort_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:27:39 by amery             #+#    #+#             */
/*   Updated: 2023/03/17 16:32:16 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_tab ab)
{
	if (ab.a[0] > ab.a[1] && ab.a[0] > ab.a[2]
		&& ab.sb >= 2 && ab.b[0] < ab.b[1])
		choice_fun(ab, &rotate, "rr");
	else if (ab.a[1] > ab.a[0] && ab.a[1] > ab.a[2]
		&& ab.sb >= 2 && ab.b[0] < ab.b[1])
		choice_fun(ab, &rotate, "rrr");
	else if (ab.a[0] > ab.a[1] && ab.a[0] > ab.a[2])
		choice_fun(ab, &rotate, "ra");
	else if (ab.a[1] > ab.a[0] && ab.a[1] > ab.a[2])
		choice_fun(ab, &rotate, "rra");
	if (ab.a[0] > ab.a[1] && ab.sb >= 2 && ab.b[0] < ab.b[1])
		choice_fun(ab, &swap, "ss");
	else if (ab.a[0] > ab.a[1])
		choice_fun(ab, &swap, "sa");
}

void	goto_a(t_tab ab, t_g g, int n)
{
	g.i = 0;
	while (g.i < ab.sa && ab.a[g.i] != n)
		g.i++;
	if (g.i > (g.i - ab.sa) * -1 && ab.a[g.i] == n)
	{
		g.i = (g.i - ab.sa) * -1;
		while (g.i-- > 0)
			choice_fun(ab, &rotate, "rra");
	}
	else if (ab.a[g.i] == n)
	{
		while (g.i-- > 0)
			choice_fun(ab, &rotate, "ra");
	}
}

static void	push_to_b(t_tab ab)
{
	if (ab.a[0] == get_nsmallest(ab.a, 1, ab.sa)
		|| (!ab.sb && ab.a[0] == get_nsmallest(ab.a, 2, ab.sa))
		|| (!ab.sb && ab.a[0] == get_nsmallest(ab.a, ab.sa, ab.sa)))
		choice_fun(ab, &push, "pb");
	else if (ab.a[1] == get_nsmallest(ab.a, 1, ab.sa)
		|| (!ab.sb && ab.a[1] == get_nsmallest(ab.a, 2, ab.sa))
		|| (!ab.sb && ab.a[1] == get_nsmallest(ab.a, ab.sa, ab.sa)))
		choice_fun(ab, &rotate, "ra");
	else
		choice_fun(ab, &rotate, "rra");
}

void	sort_five(t_tab ab, t_g g)
{
	if (ab.sa == 4 && is_three_sort(ab))
		goto_a(ab, g, get_nsmallest(ab.a, 1, ab.sa));
	while ((!ab.sb || (ab.sa == 4 && ab.sb == 1))
		&& !ft_issorta(ab.a, ab.sa, 0))
	{
		push_to_b(ab);
		ab.sa = *ab.psa;
		ab.sb = *ab.psb;
	}
	sort_three(ab);
	while (ab.sb > 0)
	{
		ab.sa = *ab.psa;
		ab.sb = *ab.psb;
		if (ab.sb)
			choice_fun(ab, &push, "pa");
		if (ab.a[0] > ab.a[ab.sa - 1])
			choice_fun(ab, &rotate, "ra");
		else if (ab.a[0] > ab.a[1])
			choice_fun(ab, &swap, "sa");
	}
}
