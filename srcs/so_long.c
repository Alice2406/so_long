/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:14:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/25 17:08:25 by aniezgod         ###   ########.fr       */
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

//PARTIE OBLIGATOIRE
//LEAKS
//separer les bonus de la version normale
//norminette
//BONUS
//gerer les problemes avec mon ennemie : ne bouge parfois pas dans la map pacman 
//probleme enemie -> teleportation de mon ennemie inexplicable  ????
//mettre un compteur de move sur ta fenetre (voir le so long pacman)

//regarder code pour separer bonus de version normale
//regarder comment mettre le compteur + sprite numero

//relink ????
//tri so_long.h