/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:24:13 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/21 19:11:48 by aniezgod         ###   ########.fr       */
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
	int	door;
	int bomb;
}				t_map;

typedef struct	s_error {
	int exit;
	int	player;
	int bomb;
	int char_map;
	int shape;
	int wall;
}				t_error;

//------MAP------//

int check_map(t_map *s, char **av, t_error *error);
char    **read_map(t_map *s, char *av);
int check_shape(t_map *s, char **tab, t_error *error);
t_map   init_struct(void);
int check_char(t_map *s, char **tab, t_error *error);
t_error init_error(void);
int find_error(t_error *error, char **tab);
int    print_error(char *msg, char **tab);
char	ft_strchr2(const char *s, int c);
int check_wall(char **tab, t_error *error, t_map *s);


#endif