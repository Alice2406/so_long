/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:24:13 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/27 16:36:32 by aniezgod         ###   ########.fr       */
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

typedef	struct s_mlx {
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

// typedef struct s_data { 
// 	struct t_map	*s;
// 	struct t_error	*error;
// 	struct t_mlx	*m;
// }				t_data;

//------CHECK_MAP--------//

char	**read_map(t_map *s, char *av);
char	**check_map(t_map *s, char **av, t_error *error);
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

#endif

//corriger l'erreur de merde 
//mettre en place ma nouvelle structure avec tab
//gerer les leaks
//etudier et mettre en place le backtracking --> regarder la video et check discord pour savoir ce qu'il faut faire
//recheck et les leaks et la norminette 
//verifier l'enonce pour etre sur que j'ai repondu a toutes les attentes


//A faire cette semaine
//essayer de finir so_long
//corriger quelqu'un pour avoir 3 points
//corriger mon so_long peu importe si il est correct ou non 
// Bon couurage meuf !! You can do it !! I'm so proud of you girl !! 