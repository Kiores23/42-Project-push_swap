/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:41 by amery             #+#    #+#             */
/*   Updated: 2023/03/20 19:29:54 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	if (!ps_verif(arg, ab.sa))
		return (ft_rerror());
	ab.psa = &ab.sa;
	ab.psb = &ab.sb;
	ab.a = create_a(arg, ab.sa);
	ab.b = create_b(ab.sa);
	if (!ab.a || !ab.b || !checkdouble(ab))
		return (free_tab(ab) + ft_rerror());
	if (!ft_issorta(ab.a, *ab.psa, 0))
		list = checker(list);
	if (!list && !ft_issorta(ab.a, *ab.psa, 0))
		return (free_tab(ab) + ft_rerror());
	sort(ab, list);
	if (ft_issorta(ab.a, *ab.psa, 0))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (free_tab(ab) + free_list(list));
}
