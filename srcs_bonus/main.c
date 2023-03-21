/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:41 by amery             #+#    #+#             */
/*   Updated: 2023/03/21 13:16:13 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	freexit(int argc, char *argv[], t_tab ab, char **arg)
{
	ab.sa = *ab.psa;
	ab.sb = *ab.psb;
	if (argc <= 1 && ab.sa > argc - 1 && ft_strchr(argv[1], ' ') && arg)
		free_julien(arg);
	free_tab(ab);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_tab	ab;
	char	**list;
	char	**arg;

	list = NULL;
	ab.sa = argc - 1;
	ab.sb = 0;
	arg = argv + 1;
	if (!ab.sa)
		return (0);
	else if (ab.sa == 1 && ft_strchr(arg[0], ' '))
		arg = ft_julien(&ab, arg);
	else if (ab.sa > 1 && !check_julien(arg, ab.sa))
		return (ft_rerror());
	if (!ps_verif(arg, ab.sa))
		return (freexit(argc, argv, ab, arg) + free_list(list) + ft_rerror());
	list = create_ab(&ab, list, arg);
	if (!list)
		return (freexit(argc, argv, ab, arg) + free_list(list) + ft_rerror());
	if (ft_issorta(ab.a, *ab.psa, 0))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (freexit(argc, argv, ab, arg) + free_list(list));
}
