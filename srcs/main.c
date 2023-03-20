/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:42:41 by amery             #+#    #+#             */
/*   Updated: 2023/03/20 18:40:51 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	**arg;
	t_tab	ab;

	ab.sa = argc - 1;
	ab.sb = 0;
	arg = argv + 1;
	if (ab.sa == 0)
		return (0);
	else if (ab.sa == 1 && ft_strchr(arg[0], ' '))
		arg = ft_julien(&ab, arg);
	if (!ps_verif(arg, ab.sa))
		return (ft_rerror());
	ab.psa = &ab.sa;
	ab.psb = &ab.sb;
	ab.a = create_a(arg, ab.sa);
	ab.b = create_b(ab.sa);
	ab.sa = *ab.psa;
	ab.sb = *ab.psb;
	if (!ab.a || !ab.b)
		return (free_tab(ab) + ft_rerror());
	if (!ft_issorta(ab.a, ab.sa, 0))
		sort(ab);
	return (free_tab(ab));
}
