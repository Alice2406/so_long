/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:24:13 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/22 15:55:19 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

typedef struct s_map {
	int	height;
	int	width;
	int	player;
	int	door;
	int	bomb;
}				t_map;

typedef struct s_error {
	int	exit;
	int	player;
	int	bomb;
	int	char_map;
	int	shape;
	int	wall;
}				t_error;

typedef struct s_data{
	void	*img;
	int		x;
	int		y;
}				t_data;
//------CHECK_MAP--------//

int		check_map(t_map *s, char **av, t_error *error);
char	**read_map(t_map *s, char *av);
int		check_shape(t_map *s, char **tab, t_error *error);
void	check_line(char *str, t_error *error);
int		check_wall(char **tab, t_error *error, t_map *s);
char	ft_strchr2(const char *s, int c);
void	count_char(t_map *s, char c);
void	check_nb_item(t_map *s, t_error *error);
int		check_char(t_map *s, char **tab, t_error *error);

//------INIT_STRUC------//

t_map	init_struct(void);
t_error	init_error(void);

//--------ERROR---------//

int		find_error(t_error *error, char **tab);
int		print_error(char *msg, char **tab);

#endif