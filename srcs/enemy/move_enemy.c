/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:15:07 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/16 12:36:44 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_bomb_door(t_data *d, int x, int y)
{
	if (d->s->door == 1)
	{
		mlx_put_image_to_window(d->m->mlx, d->m->win,
			d->t->door, y * 32, x * 32);
		d->m->tab[x][y] = 'E';
	}
	else if (d->s->bomb == 1)
	{
		mlx_put_image_to_window(d->m->mlx, d->m->win,
			d->t->bomb, y * 32, x * 32);
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
		mlx_put_image_to_window(d->m->mlx, d->m->win,
			d->t->sol, y * 32, x * 32);
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
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->e->ew, j, i);
}

void	move_south(t_data *d, int x, int y)
{
	int	i;
	int	j;

	if (d->s->door != 1 && d->s->bomb != 1)
	{
		mlx_put_image_to_window(d->m->mlx, d->m->win,
			d->t->sol, y * 32, x * 32);
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
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->e->es, j, i);
}

void	move_west(t_data *d, int x, int y)
{
	int	i;
	int	j;

	if (d->s->door != 1 && d->s->bomb != 1)
	{
		mlx_put_image_to_window(d->m->mlx, d->m->win,
			d->t->sol, y * 32, x * 32);
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
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->e->ea, j, i);
}

void	move_east(t_data *d, int x, int y)
{
	int	i;
	int	j;

	if (d->s->door != 1 && d->s->bomb != 1)
	{
		mlx_put_image_to_window(d->m->mlx, d->m->win,
			d->t->sol, y * 32, x * 32);
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
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->e->ed, j, i);
}
