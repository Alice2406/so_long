/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:14:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/22 17:52:35 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		print_error("Nb of arguments", NULL);
	data = data_init();
	check_map(data, av);
	find_error(data);
	set_map(data->s->height, data->s->width, data);
}

//LEAKS
//separer les bonus de la version normale 
//maintenir la touche -> continue d'avancer
//gerer le segfaut de la croix 
//https://harm-smits.github.io/42docs/libs/minilibx/events.html 
//-> pour la continuite de la touche
//gerer les problemes avec mon ennemie : ne bouge parfois pas dans la map pacman 
//gerer le contact entre mon ennemie et mon player -> perte de vie -> voir le probleme
//probleme -> teleportation de mon ennemie inexplicable  
//si tu as le temps :  representer la vie par des sprites <heart>
//si tu as le temps encore : mettre un logo a ton so_long
//mettre un compteur de move sur ta fenetre (voir le so long pacman)
