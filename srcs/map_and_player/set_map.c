/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:12:28 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/25 15:51:47 by aniezgod         ###   ########.fr       */
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

int	red_cross(t_data *s) //a deplacer 
{
	ft_printf("Red cross\n");
	exit(0123);
	return (0);
}

void	set_map(int x, int y, t_data *d)
{
	d->s->bomb = 0;
	d->s->door = 0;
	d->m->mlx = mlx_init();
	d->m->win = mlx_new_window(d->m->mlx, ((x - 1) * 32), (y * 32), "so_long");
	item_location(d);
	player_place(d);
	mlx_hook(d->m->win, 33, (0L), red_cross, d);
	mlx_hook(d->m->win, 2, 1L << 0, putstr_key, d);
	if (d->m->enemy == 1)
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
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, FIRE, &d->m->x, &d->m->y);
	// else if (c == 'P' && !BONUS)
	// 	d->m->img = mlx_xpm_file_to_image(d->m->mlx, PBON, &d->m->x, &d->m->y);
	else if (c == 'C')
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, BOMB, &d->m->x, &d->m->y);
	else if (c == 'N')
	{
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, ESD, &d->m->x, &d->m->y);
		d->m->enemy++;
	}
	else
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, DOOR, &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, d->m->a, d->m->b);
	show_heart(1, d);
}