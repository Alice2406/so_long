/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:14:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/14 18:38:53 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;
	int		fd;

	if (ac != 2)
		print_error("Nb of arguments", NULL, 0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		print_error("The file doesn't exist", NULL, 0);
	close (fd);
	data = data_init();
	check_map(data, av);
	find_error(data);
	set_map(data->s->height, data->s->width, data);
}

//LEAKS
//norminette
//relink ????
//mettre a jour le .h
//error avec init data ??? 

/*
CHECK ON BASIC MAP AND ON BONUS MAP

ERROR (BASIC MAP / BONUS MAP)
	- argument <2 et >2 OK OK
	- empty file OK OK
	- not a .ber OK OK
	- file not exist OK OK
	- character not allowed OK OK
	- map not rectangular OK OK
	- map not surrounded by wall OK OK
	- nb exit incorrect OK OK
	- nb player incorrect OK OK
	- nb collective incorrect OK OK
	- no way possible OK OK

ERROR BONUS 
	- too many enemies on the map OK

CHECK ON BASIC MAP
	- leaks when you win the game
	- leaks when you press red cross 
	- leaks when you press esc
	- leaks when you press control c 

CHECK ON BONUS MAP
	- leaks when you win the game
	- leaks when you press red cross
	- leaks when you press esc 
	- leaks when you press control c
	- leaks when the enemy kill you
*/