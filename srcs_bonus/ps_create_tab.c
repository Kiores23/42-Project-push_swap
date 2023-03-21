/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:19 by amery             #+#    #+#             */
/*   Updated: 2023/03/21 13:19:52 by amery            ###   ########.fr       */
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

char	**create_ab(t_tab *ab, char **list, char **arg)
{
	ab->psa = &ab->sa;
	ab->psb = &ab->sb;
	ab->a = create_a(arg, ab->sa);
	ab->b = create_b(ab->sa);
	if (!ab->a || !ab->b || !checkdouble(*ab))
		return (NULL);
	if (!ft_issorta(ab->a, *ab->psa, 0))
		list = checker(list);
	if (!list && !ft_issorta(ab->a, *ab->psa, 0))
		return (NULL);
	sort(*ab, list);
	if (!list)
		list = ft_split("is sort", ' ');
	return (list);
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
