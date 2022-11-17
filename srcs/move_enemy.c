/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:15:07 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/17 15:54:26 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_north(t_data *d, int x, int y)
{
	int i;
	int j;

	d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, x * 32, y * 32);
	d->m->tab[y][x] = '0';
	d->m->tab[y - 1][x] = 'N';
	i = (y * 32) - 32;
	j = x * 32;
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, "./textures/bonus/ESD.xpm", &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, j, i);
}

void	move_south(t_data *d, int x, int y)
{
	int i;
	int j;

	d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, x * 32, y * 32);
	d->m->tab[y][x] = '0';
	d->m->tab[y + 1][x] = 'N';
	i = (y * 32) + 32;
	j = x * 32;
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, "./textures/bonus/ESD.xpm", &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, j, i);
}

void	move_west(t_data *d, int x, int y)
{
	int i;
	int j;
	
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, x * 32, y * 32);
	d->m->tab[y][x] = '0';
	d->m->tab[y][x - 1] = 'N';
	i = y * 32;
	j = (x * 32) - 32;
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, "./textures/bonus/ESA.xpm", &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, j, i);
}

void move_est(t_data *d, int x, int y)
{
	int i;
	int j;
	
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, x * 32, y * 32);
	d->m->tab[y][x] = '0';
	d->m->tab[y][x + 1] = 'N';
	i = y * 32;
	j = (x * 32) + 32;
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, "./textures/bonus/ESA.xpm", &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, j, i);
}

void	one_way(t_data *d, int x, int y)
{
	if (d->m->north == 1)
		move_north(d, x, y);
	if (d->m->south == 1)
		move_south(d, x, y);
	if (d->m->west == 1)
		move_west(d, x, y);
	if (d->m->est == 1)
		move_est(d, x, y);
}