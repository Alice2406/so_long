/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:14:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/03 12:04:23 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	s;
	t_error	error;
	t_mlx	m;
	t_way	way;
	char	**tab;

	if (ac != 2)
		print_error("Nb of arguments", NULL);
	tab = check_map(&s, av, &error, &way);
	find_error(&error, tab);
	ft_memset(&m, 0, sizeof(t_mlx));
	set_map(&m, tab, s.height, s.width);
}
