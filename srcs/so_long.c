/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:14:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/15 16:55:37 by aniezgod         ###   ########.fr       */
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
//maintenir la touche -> continue d'avancer
//https://harm-smits.github.io/42docs/libs/minilibx/events.html 
//-> pour la continuite de la touche et pour esc/ croix rouge 
//sprite eau (ennemies)
//		-bouge en a des endroits bien precis de la map
//(de droite a gauche ou de haut en bas)
//		-fais retrecir la flamme si contact
//compteur de mouvement en bas de l'ecran 
//nom de mon so long en bas de l'ecran 

//regarder comment on fais les mouvements 
//comment on peut afficher un compteur sur l'ecran 
//gerer la croix et esc 
//faire un logo so long
//telecharger mes sprites
