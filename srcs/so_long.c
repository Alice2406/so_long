/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:14:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/28 12:14:30 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	s;
	t_error	error;
	t_mlx	m;
	char	**tab;

	if (ac != 2)
		print_error("Nb of arguments", NULL);
	tab = check_map(&s, av, &error, tab);
	find_error(&error, tab);
	ft_memset(&m, 0, sizeof(t_mlx));
	set_map(&m, tab, s.height, s.width);
}

//check_bomb //done
//check_char_map //done 
//check wall // done

//check_map 
//ft_error
//so_long


//move_player
//set_map
