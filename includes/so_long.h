/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:24:13 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/01 18:14:59 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

# define W	119
# define A	97
# define D	100
# define S	115

# define TERRAIN	"./textures/terrain.xpm"
# define FIRE	"./textures/fire.xpm"
# define WALL	"./textures/wall.xpm"
# define BOMB	"./textures/bomb.xpm"
# define DOOR	"./textures/door.xpm"

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

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	int		x;
	int		y;
	// int		bits_per_pixel;
	// int		endian;
	// int		line_length;
	// char	*addr;
	int		a;
	int		b;
	int		key;
	char	**tab;
}				t_mlx;

typedef struct s_way {
	char	**map;
	int		exit;
	int		bomb;
	int		tbomb;
	int		x;
	int		y;
}

//------CHECK_MAP--------//

char	**read_map(t_map *s, char *av, char **tab);
char	**check_map(t_map *s, char **av, t_error *error, char **tab);
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

void	item_location(t_mlx *m, char **tab);
void	show_map(t_mlx *m, char c);
void	set_map(t_mlx *m, char **tab, int x, int y);
void	move_player(t_mlx *m);
void	player_place(t_mlx *m);
int		check_tab(t_mlx *m);
void	check_way(char **tab, t_way *w, t_error *error);
void	flood_fill(char c, t_way *w, int a, int b);

#endif
