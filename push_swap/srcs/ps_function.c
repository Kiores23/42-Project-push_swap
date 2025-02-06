/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:24 by amery             #+#    #+#             */
/*   Updated: 2023/03/16 12:50:47 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_reverse(t_tab ab, char *cmd);

t_tab	choice(t_tab ab, char c)
{
	if (c == 'a')
	{
		ab.c = ab.a;
		ab.sc = ab.sa;
		ab.d = ab.b;
		ab.sd = ab.sb;
	}
	else if (c == 'b')
	{
		ab.c = ab.b;
		ab.sc = ab.sb;
		ab.d = ab.a;
		ab.sd = ab.sa;
	}
	return (ab);
}

void	swap(t_tab ab, char *cmd)
{
	int	tmp;

	if ((!ft_strcmp(cmd, "sa") || !ft_strcmp(cmd, "ss")) && ab.sa > 1)
		ab = choice(ab, 'a');
	else if (!ft_strcmp(cmd, "sb") && ab.sb > 1)
		ab = choice(ab, 'b');
	else
		return ;
	tmp = ab.c[1];
	ab.c[1] = ab.c[0];
	ab.c[0] = tmp;
	if (!ft_strcmp(cmd, "ss"))
		swap(ab, "sb");
}

void	push(t_tab ab, char *cmd)
{
	if (!ft_strcmp(cmd, "pa") && ab.sb > 0)
	{
		ab.sa++;
		*ab.psa = ab.sa;
		rotate_reverse(ab, "rra");
		*ab.a = *ab.b;
		*ab.b = 0;
		rotate(ab, "rb");
		*ab.psb = ab.sb - 1;
	}
	else if (!ft_strcmp(cmd, "pb") && ab.sa > 0)
	{
		ab.sb++;
		*ab.psb = ab.sb;
		rotate_reverse(ab, "rrb");
		*ab.b = *ab.a;
		*ab.a = 0;
		rotate(ab, "ra");
		*ab.psa = ab.sa - 1;
	}
}

void	rotate(t_tab ab, char *cmd)
{
	int	tmp;
	int	tmp2;
	int	i;

	if (!ft_strcmp(cmd, "rra") || !ft_strcmp(cmd, "rrb")
		|| !ft_strcmp(cmd, "rrr"))
		return (rotate_reverse(ab, cmd));
	if (!ft_strcmp(cmd, "ra") || !ft_strcmp(cmd, "rr"))
		ab = choice(ab, 'a');
	else if (!ft_strcmp(cmd, "rb"))
		ab = choice(ab, 'b');
	i = ab.sc;
	if (i - 1 > 0)
		tmp = ab.c[i - 1];
	while (--i > 0)
	{
		if (i == ab.sc - 1)
			ab.c[i] = ab.c[0];
		tmp2 = ab.c[i - 1];
		ab.c[i - 1] = tmp;
		tmp = tmp2;
	}
	if (!ft_strcmp(cmd, "rr"))
		rotate(ab, "rb");
}

static void	rotate_reverse(t_tab ab, char *cmd)
{
	int	tmp;
	int	tmp2;
	int	i;

	if (!ft_strcmp(cmd, "rra") || !ft_strcmp(cmd, "rrr"))
		ab = choice(ab, 'a');
	else if (!ft_strcmp(cmd, "rrb"))
		ab = choice(ab, 'b');
	i = -1;
	if (i + 1 < ab.sc)
		tmp = ab.c[0];
	while (++i < ab.sc - 1)
	{
		if (i == 0)
			ab.c[0] = ab.c[ab.sc - 1];
		tmp2 = ab.c[i + 1];
		ab.c[i + 1] = tmp;
		tmp = tmp2;
	}
	if (!ft_strcmp(cmd, "rrr"))
		rotate_reverse(ab, "rrb");
}
