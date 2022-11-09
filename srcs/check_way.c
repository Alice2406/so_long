/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:03:27 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/09 13:34:24 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fire_place(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	while (d->w->map[i])
	{
		j = 0;
		while (d->w->map[i][j])
		{
			if (d->w->map[i][j] == 'P')
			{
				d->w->x = i;
				d->w->y = j;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_data *d, int x, int y)
{
	if (d->w->map[x][y] == '1' || d->w->map[x][y] == 'x')
		return ;
	if (d->w->map[x][y] == 'C')
		d->w->bomb++;
	if (d->w->map[x][y] == 'E')
		d->w->exit++;
	d->w->map[x][y] = 'x';
	flood_fill(d, x, y + 1);
	flood_fill(d, x - 1, y);
	flood_fill(d, x, y - 1);
	flood_fill(d, x + 1, y);
	return ;
}

void	check_way(char **tab, t_data *d)
{
	int	x;
	int	y;

	d->w->map = tab;
	fire_place(d);
	x = d->w->x;
	y = d->w->y;
	flood_fill(d, x, y);
	if (d->w->exit != 1 || d->s->bomb != d->w->bomb)
		d->error->way = 1;
}
