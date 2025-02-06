/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:50:15 by amery             #+#    #+#             */
/*   Updated: 2023/03/20 19:37:49 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_list(char **list)
{
	int	i;

	i = 0;
	while (list && list[i])
	{
		free(list[i]);
		i++;
	}
	if (list)
		free(list);
	return (0);
}

char	**checker(char **list)
{
	int	i;

	i = 0;
	list = malloc(sizeof(char *) * 10000);
	if (!list)
		return (NULL);
	while (list && (!i || (list[i - 1] && list[i - 1][0] != 127)) && i < 10000)
	{
		list[i] = get_next_line(0);
		if (list[i] && ft_strcmp(list[i], "sa\n") && ft_strcmp(list[i], "sb\n")
			&& ft_strcmp(list[i], "ss\n") && ft_strcmp(list[i], "ra\n")
			&& ft_strcmp(list[i], "rra\n") && ft_strcmp(list[i], "rb\n")
			&& ft_strcmp(list[i], "rrb\n") && ft_strcmp(list[i], "rr\n")
			&& ft_strcmp(list[i], "rrr\n") && ft_strcmp(list[i], "pa\n")
			&& ft_strcmp(list[i], "pb\n"))
		{
			free_list(list);
			list = NULL;
			break ;
		}
		i++;
	}
	return (list);
}
