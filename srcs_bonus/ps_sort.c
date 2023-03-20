/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:29 by amery             #+#    #+#             */
/*   Updated: 2023/03/20 11:34:58 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choice_fun(t_tab ab, char *cmd)
{
	if (cmd[0] == 's')
		swap(ab, cmd);
	else if (cmd[0] == 'p')
		push(ab, cmd);
	else if (cmd[0] == 'r')
		rotate(ab, cmd);
	ab.sa = *ab.psa;
	ab.sb = *ab.psb;
}

void	sort(t_tab ab, char **list)
{
	int	i;

	i = -1;
	if (!list)
		return ;
	while (list[++i])
	{
		ab.sa = *ab.psa;
		ab.sb = *ab.psb;
		choice_fun(ab, list[i]);
	}
	return ;
}
