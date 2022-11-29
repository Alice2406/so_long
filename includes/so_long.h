/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:24:13 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/29 14:04:37 by aniezgod         ###   ########.fr       */
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
# define HEART_F	"./textures/bonus/full_heart.xpm"
# define HEART_E	"./textures/bonus/empty_heart.xpm"


// #ifndef BONUS
// # define BONUS 1
// #endif
// # define BONUS 0

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

//------CHECK_MAP--------//

void	read_map(t_data *d, char *av);
void	check_map(t_data *d, char **av);
int	check_shape(t_data *d);
void	check_line(char *str, t_data *d);
int	check_wall(t_data *d);
char	ft_strchr2(const char *s, int c);
void	count_char(t_data *d, char c);
void	check_nb_item(t_data *d);
int	check_char(t_data *d);


//------INIT_STRUC------//

t_data	*data_init(void);

//--------ERROR---------//

int	find_error(t_data *d);
int	print_error(char *msg, t_data *d);

void	item_location(t_data *d);
void	show_map(t_data *d, char c);
void	set_map(int x, int y, t_data *d);
void	move_player(t_data *d);
void	player_place(t_data *d);
int	check_tab(t_data *d);
void	check_way(char **tab, t_data *d);
void	flood_fill(t_data *d, int x, int y);
void	print_img_move(t_data *d);

//-------BONUS------//

void	move_player_bonus(t_data *d);
void	check_life(t_data *d);
void	move_right_or_left_bonus(t_data *d, char *stade);
void	move_back_or_front_bonus(t_data *d, char *stade);
int destroy_window(t_data *d);
static int nb_line_file(char *str);

int	anim(t_data *d);
void	one_way(t_data *d, int x, int y);
void	ft_way(t_data *d, int x, int y);
void two_ways(t_data *d, int x, int y);
void move_east(t_data *d, int x, int y);
void	move_west(t_data *d, int x, int y);
void	move_south(t_data *d, int x, int y);
void	move_north(t_data *d, int x, int y);
void three_ways(t_data *d, int x, int y);
void	ns_or_we_comp(t_data *d, int x, int y);
void	nw_comp(t_data *d, int x, int y);
void	ne_comp(t_data *d, int x, int y);
void	sw_comp(t_data *d, int x, int y);
void	se_comp(t_data *d, int x, int y);
void	nsw_or_nse_comp(t_data *d, int x, int y);
void	wes_or_wen_comp(t_data *d, int x, int y);
void	four_ways(t_data *d, int x, int y);

char	*stade_one(t_data *d);
char	*stade_two(t_data *d);
char	*stade_three(t_data *d);
void	show_heart(int i, t_data *d);
void	ft_update_score(t_data *d, int score);


#endif