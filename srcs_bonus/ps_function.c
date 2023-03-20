/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:24 by amery             #+#    #+#             */
/*   Updated: 2023/03/17 20:09:55 by amery            ###   ########.fr       */
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

	if ((!ft_strcmp(cmd, "sa\n") || !ft_strcmp(cmd, "ss\n")) && ab.sa > 1)
		ab = choice(ab, 'a');
	else if (!ft_strcmp(cmd, "sb\n") && ab.sb > 1)
		ab = choice(ab, 'b');
	else
		return ;
	tmp = ab.c[1];
	ab.c[1] = ab.c[0];
	ab.c[0] = tmp;
	if (!ft_strcmp(cmd, "ss\n"))
		swap(ab, "sb\n");
}

void	push(t_tab ab, char *cmd)
{
	if (!ft_strcmp(cmd, "pa\n") && ab.sb > 0)
	{
		ab.sa++;
		*ab.psa = ab.sa;
		rotate_reverse(ab, "rra\n");
		*ab.a = *ab.b;
		*ab.b = 0;
		rotate(ab, "rb\n");
		*ab.psb = ab.sb - 1;
	}
	else if (!ft_strcmp(cmd, "pb\n") && ab.sa > 0)
	{
		ab.sb++;
		*ab.psb = ab.sb;
		rotate_reverse(ab, "rrb\n");
		*ab.b = *ab.a;
		*ab.a = 0;
		rotate(ab, "ra\n");
		*ab.psa = ab.sa - 1;
	}
}

void	rotate(t_tab ab, char *cmd)
{
	int	tmp;
	int	tmp2;
	int	i;

	if (!ft_strcmp(cmd, "rra\n") || !ft_strcmp(cmd, "rrb\n")
		|| !ft_strcmp(cmd, "rrr\n"))
		return (rotate_reverse(ab, cmd));
	if (!ft_strcmp(cmd, "ra\n") || !ft_strcmp(cmd, "rr\n"))
		ab = choice(ab, 'a');
	else if (!ft_strcmp(cmd, "rb\n"))
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
	if (!ft_strcmp(cmd, "rr\n"))
		rotate(ab, "rb\n");
}

static void	rotate_reverse(t_tab ab, char *cmd)
{
	int	tmp;
	int	tmp2;
	int	i;

	if (!ft_strcmp(cmd, "rra\n") || !ft_strcmp(cmd, "rrr\n"))
		ab = choice(ab, 'a');
	else if (!ft_strcmp(cmd, "rrb\n"))
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
	if (!ft_strcmp(cmd, "rrr\n"))
		rotate_reverse(ab, "rrb\n");
}
