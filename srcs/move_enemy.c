/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:15:07 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/18 16:06:22 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_north(t_data *d, int x, int y)
{
	int i;
	int j;

	d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, y * 32, x * 32);
	d->m->tab[x][y] = '0';
	d->m->tab[x - 1][y] = 'N';
	i = (x * 32) - 32;
	j = y * 32;
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, "./textures/bonus/ESD.xpm", &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, j, i);
}

void	move_south(t_data *d, int x, int y)
{
	int i;
	int j;

	d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, y * 32, x * 32);
	d->m->tab[x][y] = '0';
	d->m->tab[x + 1][y] = 'N';
	i = (x * 32) + 32;
	j = y * 32;
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, "./textures/bonus/ESD.xpm", &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, j, i);
}

void	move_west(t_data *d, int x, int y)
{
	int i;
	int j;
	
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, y * 32, x * 32);
	d->m->tab[x][y] = '0';
	d->m->tab[x][y - 1] = 'N';
	i = x * 32;
	j = (y * 32) - 32;
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, "./textures/bonus/ESA.xpm", &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, j, i);
}

void move_east(t_data *d, int x, int y)
{
	int i;
	int j;
	
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, y * 32, x * 32);
	d->m->tab[x][y] = '0';
	d->m->tab[x][y + 1] = 'N';
	i = x * 32;
	j = (y * 32) + 32;
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, "./textures/bonus/ESA.xpm", &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, j, i);
}

//mettre le comportement a avoir si l'ennemi va sur un collective l'exit 
//faire perdre de la vie au player si l'ennemi et le player se rencontre -> mettre le player au stade inferieur et si playeur boule -> mort du perso !