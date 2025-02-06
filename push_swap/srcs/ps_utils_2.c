/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:38:24 by amery             #+#    #+#             */
/*   Updated: 2023/03/17 16:31:09 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	consecutive_three(t_tab ab, int i, int j, int k)
{
	int	tmp;

	tmp = get_nsmallest(ab.a, j - (ab.sa - i) + k + 1, ab.sa);
	if (i + k < ab.sa && get_nsmallest(ab.a, j + k, ab.sa) == ab.a[i + k])
		return (1);
	else if (i + k >= ab.sa && tmp == ab.a[k - (ab.sa - i)])
		return (1);
	return (0);
}

int	is_three_sort(t_tab ab)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < ab.sa)
	{
		j = 0;
		while (++j <= ab.sa - 2)
		{
			k = 0;
			while (consecutive_three(ab, i, j, k++) && k < 3)
				;
			if (k == 3)
				return (1);
		}
	}
	return (0);
}
