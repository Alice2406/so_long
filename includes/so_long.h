/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:24:13 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/09 16:30:47 by aniezgod         ###   ########.fr       */
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
# define ESC	65307

# define SOL	"./textures/terrain.xpm"
# define FIRE	"./textures/fire.xpm"
# define WALL	"./textures/wall.xpm"
# define BOMB	"./textures/bomb.xpm"
# define DOOR	"./textures/door.xpm"
# define ESD	"./textures/bonus/ESD.xpm"
# define ESA	"./textures/bonus/ESA.xpm"
# define ESS	"./textures/bonus/ESS.xpm"
# define ESW	"./textures/bonus/ESW.xpm"
# define PBON	"./textures/bonus/S1PA.xpm"
# define ZERO	"./textures/bonus/0.xpm"
# define ONE	"./textures/bonus/1.xpm"
# define TWO	"./textures/bonus/2.xpm"
# define THREE	"./textures/bonus/3.xpm"
# define FOUR	"./textures/bonus/4.xpm"
# define FIVE	"./textures/bonus/5.xpm"
# define SIX	"./textures/bonus/6.xpm"
# define SEVEN	"./textures/bonus/7.xpm"
# define EIGHT	"./textures/bonus/8.xpm"
# define NINE	"./textures/bonus/9.xpm"
# define FULL	"./textures/bonus/full_heart.xpm"
# define EMPTY	"./textures/bonus/empty_heart.xpm"

# ifndef BONUS
#  define BONUS 0
# endif

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
	int	enemy;
}				t_error;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	int		x;
	int		y;
	int		a;
	int		b;
	int		key;
	char	**tab;
	int		enemyspeed;
	int		north;
	int		south;
	int		west;
	int		east;
	int		nb_way;
	int		life;
	int		enemy;
}				t_mlx;

typedef struct s_way {
	int		exit;
	int		bomb;
	int		tbomb;
	int		x;
	int		y;
}				t_way;

typedef struct s_data {
	struct s_map	*s;
	struct s_error	*error;
	struct s_way	*w;
	struct s_mlx	*m;
}				t_data;

//---------PARSING----------//

t_data	*data_init(void);
char	ft_strchr2(const char *s, int c);
int		check_shape(t_data *d);
int		check_tab(t_data *d);
int		check_char(t_data *d);
int		check_wall(t_data *d);
void	check_map(t_data *d, char **av);
void	read_map(t_data *d, char *av);
void	check_nb_item(t_data *d);
void	count_char(t_data *d, char c);
void	check_line(char *str, t_data *d);
void	check_way(char **tab, t_data *d);
void	flood_fill(t_data *d, int x, int y);
void	init_mlx(t_data *d);
void	way_init(t_data *d);
void	error_init(t_data *d);
void	map_init(t_data *d);

//------MAP_AND_PLAYER------//

void	show_map(t_data *d, char c);
void	item_location(t_data *d);
void	set_map(int x, int y, t_data *d);
//int	red_cross(t_data *s);
void	print_move(t_data *d);
void	move_player(t_data *d);
void	move_right_or_left(t_data *d);
void	move_back_or_front(t_data *d);
void	print_img_move(t_data *d);
void	player_place(t_data *d);

//-----DESTROY_AND_FREE-----//

int		destroy_window(t_data *d);
int		print_error(char *msg, t_data *d);
int		find_error(t_data *d);
void	map_destroy(t_data *d);

//-----------BONUS----------//
int		anim(t_data *d);
char	*stade_three(t_data *d);
char	*stade_two(t_data *d);
char	*stade_one(t_data *d);
void	move_anim(t_data *d);
void	re_init_struct(t_data *d);
void	ft_way(t_data *d, int x, int y);
void	nb_way(t_data *d, int x, int y);
void	move_player_bonus(t_data *d);
void	check_life(t_data *d);
void	move_right_or_left_bonus(t_data *d, char *stade);
void	move_back_or_front_bonus(t_data *d, char *stade);
void	show_heart(int i, t_data *d);
void	four_ways(t_data *d, int x, int y);
void	three_ways(t_data *d, int x, int y);
void	two_ways(t_data *d, int x, int y);
void	one_way(t_data *d, int x, int y);
void	move_east(t_data *d, int x, int y);
void	move_west(t_data *d, int x, int y);
void	move_south(t_data *d, int x, int y);
void	move_north(t_data *d, int x, int y);
void	enemy_bomb_door(t_data *d, int x, int y);
void	ft_update_score(t_data *d, int score);
void	ft_put_font(t_data *d, int digit, int i);
void	wes_or_wen_comp(t_data *d, int x, int y);
void	nsw_or_nse_comp(t_data *d, int x, int y);
void	se_comp(t_data *d, int x, int y);
void	sw_comp(t_data *d, int x, int y);
void	ne_comp(t_data *d, int x, int y);
void	nw_comp(t_data *d, int x, int y);
void	ns_or_we_comp(t_data *d, int x, int y);

#endif