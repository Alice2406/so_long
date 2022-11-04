/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:14:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/04 11:34:54 by aniezgod         ###   ########.fr       */
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

//LEAKS
//maintenir la touche -> continue d'avancer
//reunir mes structs (enfin essayer) pour gagner de la place et des mouv inutiles
//https://harm-smits.github.io/42docs/libs/minilibx/events.html -> pour la continuite de la touche et pour esc/ croix rouge 
//sprite flamme (player)
//		-augmente avec les bombes (3 ou 4) 
//sprite eau (ennemies)
//		-bouge en a des endroits bien precis de la map (de droite a gauche ou de haut en bas)
//		-fais retrecir la flamme si contact
//compteur de mouvement en bas de l'ecran 
//nom de mon so long en bas de l'ecran 

//regarder comment on fais les mouvements 
//comment on peut afficher un compteur sur l'ecran 
//gerer la croix et esc 
//faire un logo so long
//telecharger mes sprites
