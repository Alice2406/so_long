/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:14:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/03 15:42:22 by aniezgod         ###   ########.fr       */
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
//trouver un logo
