/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:15:07 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/12 16:40:30 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_bomb_door(t_data *d, int x, int y)
{
	if (d->s->door == 1)
	{
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, DOOR, &d->m->x, &d->m->y);
		mlx_put_image_to_window(d->m->mlx, d->m->win,
			d->m->img, y * 32, x * 32);
		d->m->tab[x][y] = 'E';
	}
	else if (d->s->bomb == 1)
	{
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, BOMB, &d->m->x, &d->m->y);
		mlx_put_image_to_window(d->m->mlx, d->m->win,
			d->m->img, y * 32, x * 32);
		d->m->tab[x][y] = 'C';
	}
	d->s->door = 0;
	d->s->bomb = 0;
}

void	move_north(t_data *d, int x, int y)
{
	int	i;
	int	j;

	if (d->s->door != 1 && d->s->bomb != 1)
	{
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
		mlx_put_image_to_window(d->m->mlx, d->m->win,
			d->m->img, y * 32, x * 32);
		d->m->tab[x][y] = '0';
	}
	else
		enemy_bomb_door(d, x, y);
	if (d->m->tab[x - 1][y] == 'C')
		d->s->bomb = 1;
	if (d->m->tab[x - 1][y] == 'E')
		d->s->door = 1;
	d->m->tab[x - 1][y] = 'N';
	i = (x * 32) - 32;
	j = y * 32;
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, ESW, &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, j, i);
}

void	move_south(t_data *d, int x, int y)
{
	int	i;
	int	j;

	if (d->s->door != 1 && d->s->bomb != 1)
	{
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
		mlx_put_image_to_window(d->m->mlx, d->m->win,
			d->m->img, y * 32, x * 32);
		d->m->tab[x][y] = '0';
	}
	else
		enemy_bomb_door(d, x, y);
	if (d->m->tab[x + 1][y] == 'C')
		d->s->bomb = 1;
	if (d->m->tab[x + 1][y] == 'E')
		d->s->door = 1;
	d->m->tab[x + 1][y] = 'N';
	i = (x * 32) + 32;
	j = y * 32;
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, ESS, &d->m->x, &d->m->y);
}

void	move_west(t_data *d, int x, int y)
{
	int	i;
	int	j;

	if (d->s->door != 1 && d->s->bomb != 1)
	{
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
		mlx_put_image_to_window(d->m->mlx, d->m->win,
			d->m->img, y * 32, x * 32);
		d->m->tab[x][y] = '0';
	}
	else
		enemy_bomb_door(d, x, y);
	if (d->m->tab[x][y - 1] == 'C')
		d->s->bomb = 1;
	if (d->m->tab[x][y - 1] == 'E')
		d->s->door = 1;
	d->m->tab[x][y - 1] = 'N';
	i = x * 32;
	j = (y * 32) - 32;
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, ESA, &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, j, i);
}

void	move_east(t_data *d, int x, int y)
{
	int	i;
	int	j;

	if (d->s->door != 1 && d->s->bomb != 1)
	{
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
		mlx_put_image_to_window(d->m->mlx, d->m->win,
			d->m->img, y * 32, x * 32);
		d->m->tab[x][y] = '0';
	}
	else
		enemy_bomb_door(d, x, y);
	if (d->m->tab[x][y + 1] == 'C')
		d->s->bomb = 1;
	if (d->m->tab[x][y + 1] == 'E')
		d->s->door = 1;
	d->m->tab[x][y + 1] = 'N';
	i = x * 32;
	j = (y * 32) + 32;
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, ESD, &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, j, i);
}
