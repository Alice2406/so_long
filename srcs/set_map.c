/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:12:28 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/17 14:56:10 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(void)
{
	static int	i = 1;

	ft_printf("Nb of move : %d\n", i);
	i++;
}

static int	putstr_key(int key, t_data *d)
{
	d->m->key = key;
	if (key == ESC)
		destroy_window(d);
	if (key == A || key == W || key == S || key == D)
	{
		print_move();
//		move_player(d);
		move_player_bonus(d);
	}
	return (0);
}

void	set_map(int x, int y, t_data *d)
{
	d->m->mlx = mlx_init();
	d->m->win = mlx_new_window(d->m->mlx, ((x - 1) * 32), (y * 32), "so_long");
	item_location(d);
	player_place(d);
	mlx_hook(d->m->win, 17, 1L << 2, destroy_window, &d);
	mlx_key_hook(d->m->win, putstr_key, d);
	mlx_loop_hook(d->m->mlx, anim, d);
	mlx_loop(d->m->mlx);
}

void	item_location(t_data *d)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	d->m->a = 0;
	d->m->b = 0;
	while (d->m->tab[i])
	{
		j = 0;
		while (d->m->tab[i][j])
		{
			c = d->m->tab[i][j];
			show_map(d, d->m->tab[i][j]);
			d->m->a += 32;
			j++;
		}
		d->m->a = 0;
		d->m->b += 32;
		i++;
	}
}

void	show_map(t_data *d, char c)
{
	if (c == '1')
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, WALL, &d->m->x, &d->m->y);
	else if (c == '0')
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
	else if (c == 'P')
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, "./textures/bonus/S1PA.xpm", &d->m->x, &d->m->y);
//		d->m->img = mlx_xpm_file_to_image(d->m->mlx, FIRE, &d->m->x, &d->m->y);
	else if (c == 'C')
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, BOMB, &d->m->x, &d->m->y);
	else if (c == 'N')
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, "./textures/bonus/ESD.xpm", &d->m->x, &d->m->y);
	else
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, DOOR, &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, d->m->a, d->m->b);
}
