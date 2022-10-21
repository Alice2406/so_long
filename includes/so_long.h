/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:24:13 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/21 12:19:37 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "mlx.h"
// #include <libc.h> //to delete

typedef struct	s_map {
//	char **map;
	int	height;
	int	width;
	int	player;
	int	wall;
	int	door;
	int bomb;
	int corridor;
}				t_map;

//------MAP------//

int check_map(t_map *s, char **av);
char    **read_map(t_map *s, char *av);

#endif