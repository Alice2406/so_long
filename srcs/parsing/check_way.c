/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:03:27 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/16 15:37:34 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_data *d, int x, int y)
{
	if (d->m->tab[x][y] == '1' || d->m->tab[x][y] == 'x')
		return ;
	if (d->m->tab[x][y] == 'C')
		d->w->bomb++;
	if (d->m->tab[x][y] == 'E')
		d->w->exit++;
	d->m->tab[x][y] = 'x';
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

	player_place(d);
	x = d->m->a;
	y = d->m->b;
	flood_fill(d, x, y);
	if (d->w->exit != 1 || d->s->bomb != d->w->bomb)
		d->error->way = 1;
}
