/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:14:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/25 18:39:54 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	s;
	t_error	error;
	t_data	data;
	char	**tab;
	int		height;
	int		width;

	if (ac != 2)
		print_error("Nb of arguments", NULL);
	tab = check_map(&s, av, &error);
	height = s.height;
	width = s.width;
	ft_memset(&data, 0, sizeof(t_data));
	set_map(&data, tab, height, width);
}
