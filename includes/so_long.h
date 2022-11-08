/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:24:13 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/08 14:55:43 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

//# define W	119
//# define A	97
//# define D	100
//# define S	115

# define W	13
# define A	0
# define D	2
# define S	1

# define TERRAIN	"./textures/terrain.xpm"
# define FIRE	"./textures/fire.xpm"
# define WALL	"./textures/wall.xpm"
# define BOMB	"./textures/bomb.xpm"
# define DOOR	"./textures/door.xpm"
# define P_A "./textures/player_a.xpm"
# define P_W "./textures/player_w.xpm"
# define P_S "./textures/player_s.xpm"
# define P_D "./textures/player_d.xpm"

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
	int	way;
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
}				t_way;

typedef struct s_bonus {
	int	life;
}				t_bonus;

typedef struct s_data {
	struct s_map	*s;
	struct s_error	*error;
	struct s_way	*w;
}				t_data;

//------CHECK_MAP--------//

char	**read_map(t_data *d, char *av, char **tab);
char	**check_map(t_data *d, char **av);
int		check_shape(t_data *d, char **tab);
void	check_line(char *str, t_data *d);
int		check_wall(char **tab, t_data *d);
char	ft_strchr2(const char *s, int c);
void	count_char(t_data *d, char c);
void	check_nb_item(t_data *d);
int		check_char(t_data *d, char **tab);


//------INIT_STRUC------//

t_data	*data_init(void);

//--------ERROR---------//

int		find_error(t_data *d, char **tab);
int		print_error(char *msg, char **tab);

void	item_location(t_mlx *m, char **tab);
void	show_map(t_mlx *m, char c);
void	set_map(t_mlx *m, char **tab, int x, int y);
void	move_player(t_mlx *m);
void	player_place(t_mlx *m);
int		check_tab(t_mlx *m);
void	check_way(char **tab, t_data *d);
void	flood_fill(t_data *d, int x, int y);
void	print_img_move(t_mlx *m);

//-------BONUS------//

void	move_player_bonus(t_mlx *m);
int	check_life(int life, t_mlx *m);
void	move_right_or_left_bonus(t_mlx *m, char *stade);
void	move_back_or_front_bonus(t_mlx *m, char *stade);

#endif