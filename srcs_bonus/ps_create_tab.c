/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:19 by amery             #+#    #+#             */
/*   Updated: 2023/03/20 18:54:16 by amery            ###   ########.fr       */
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
	ft_bzero(b, s);
	return (b);
}
