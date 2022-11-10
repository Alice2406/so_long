/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:12:28 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/10 16:53:31 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(void)
{
	static int	i = 1;

	ft_printf("Nb of move : %d\n", i);
	i++;
}

static int	putstr_key(int key, t_mlx *m)
{
	m->key = key;
	if (key == ESC)
		destroy_window(m);
	if (key == A || key == W || key == S || key == D)
	{
		print_move();
//		move_player(m);
		move_player_bonus(m);
	}
	return (0);
}

t_bonus	bonus_init(void)
{
	t_bonus	game;

	game.enemyspeed = 0;
	return (game);
}

void	set_map(t_mlx *m, char **tab, int x, int y, t_data *d)
{
	t_bonus game;

	game = bonus_init();
	m->tab = tab;
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, (x * 32), (y * 32), "so_long");
	item_location(m, tab);
	player_place(m);
	mlx_hook(m->win, 17, 1L << 2, destroy_window, &m);
	mlx_key_hook(m->win, putstr_key, m);
	mlx_loop_hook(m->mlx, anim, &game);
	mlx_loop(m->mlx);
}

void	item_location(t_mlx *m, char **tab)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			c = tab[i][j];
			show_map(m, tab[i][j]);
			m->a += 32;
			j++;
		}
		m->a = 0;
		m->b += 32;
		i++;
	}
}

void	show_map(t_mlx *m, char c)
{
	if (c == '1')
		m->img = mlx_xpm_file_to_image(m->mlx, WALL, &m->x, &m->y);
	else if (c == '0')
		m->img = mlx_xpm_file_to_image(m->mlx, TERRAIN, &m->x, &m->y);
	else if (c == 'P')
		m->img = mlx_xpm_file_to_image(m->mlx, "./textures/bonus/S1PA.xpm", &m->x, &m->y);
	else if (c == 'C')
		m->img = mlx_xpm_file_to_image(m->mlx, BOMB, &m->x, &m->y);
	else if (c == 'N')
		m->img = mlx_xpm_file_to_image(m->mlx, "./textures/bonus/S2PA.xpm", &m->x, &m->y);
	else
		m->img = mlx_xpm_file_to_image(m->mlx, DOOR, &m->x, &m->y);
	mlx_put_image_to_window(m->mlx, m->win, m->img, m->a, m->b);
}
