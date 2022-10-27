/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:14:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/27 16:19:16 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	s;
	t_error	error;
	t_mlx	m;
	char	**tab;
	int		height;
	int		width;

	if (ac != 2)
		print_error("Nb of arguments", NULL);
	tab = check_map(&s, av, &error);
	height = s.height;
	width = s.width;
	ft_memset(&m, 0, sizeof(t_mlx));
	set_map(&m, tab, height, width);
}

//check_bomb //done
//check_char_map //i think done 
//check_map 
//check wall // done
//ft_error
//move_player
//set_map
