/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:32:37 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/23 13:08:26 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	nb_way(t_data *d, int x, int y)
{
	if (d->m->tab[x][y - 1] != '1')
	{
		d->m->west = 1;
		d->m->nb_way++;
	}
	if (d->m->tab[x][y + 1] != '1')
	{
		d->m->east = 1;
		d->m->nb_way++;
	}
	if (d->m->tab[x + 1][y] != '1')
	{
		d->m->south = 1;
		d->m->nb_way++;
	}
	if (d->m->tab[x - 1][y] != '1')
	{
		d->m->north = 1;
		d->m->nb_way++;
	}
	ft_way(d, x, y);
}

void	ft_way(t_data *d, int x, int y)
{
	if (d->m->nb_way == 1)
		one_way(d, x, y);
	else if (d->m->nb_way == 2)
		two_ways(d, x, y);
	else if (d->m->nb_way == 3)
		three_ways(d, x, y);
	else if (d->m->nb_way == 4)
		four_ways(d, x, y);
}

void	re_init_struct(t_data *d)
{
	d->m->nb_way = 0;
	d->m->north = 0;
	d->m->south = 0;
	d->m->east = 0;
	d->m->west = 0;
}

void	move_anim(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 33)
		{
			if (d->m->tab[i][j] == 'N')
			{
				re_init_struct(d);
				nb_way(d, i, j);
			}
			j++;
		}
		i++;
	}
}

int	anim(t_data *d)
{
	d->m->enemyspeed++;
	if (d->m->enemyspeed >= 20000)
	{
		move_anim(d);
		d->m->enemyspeed = 0;
	}
	return (0);
}
