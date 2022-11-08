/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:14:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/08 16:42:23 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_mlx	m;
	char	**tab;

	if (ac != 2)
		print_error("Nb of arguments", NULL);
	data = data_init();
	tab = check_map(data, av);
	find_error(data, tab);
	ft_memset(&m, 0, sizeof(t_mlx));
	set_map(&m, tab, data->s->height, data->s->width);
}

//LEAKS
//maintenir la touche -> continue d'avancer
//https://harm-smits.github.io/42docs/libs/minilibx/events.html 
//-> pour la continuite de la touche et pour esc/ croix rouge 
//sprite flamme (player)
//		-augmente avec les bombes (3 ou 4) 
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

//APPLE
//ESC	53
//W		13
//A		0
//S		1
//D		2
//RED_CROSS		17
//LINUX
//ESC	65307
//RED_CROSS	33

//error sur check wall -> a voir 