/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:05:41 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/25 13:21:54 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	one_way(t_data *d, int x, int y)
{
	if (d->m->north == 1)
		move_north(d, x, y);
	else if (d->m->south == 1)
		move_south(d, x, y);
	else if (d->m->west == 1)
		move_west(d, x, y);
	else
		move_east(d, x, y);
}

void	two_ways(t_data *d, int x, int y)
{
	if ((d->m->north == 1 && d->m->south == 1)
		|| (d->m->west == 1 && d->m->east == 1))
		ns_or_we_comp(d, x, y);
	else if (d->m->north == 1 && d->m->west == 1)
		nw_comp(d, x, y);
	else if (d->m->north == 1 && d->m->east == 1)
		ne_comp(d, x, y);
	else if (d->m->south == 1 && d->m->west == 1)
		sw_comp(d, x, y);
	else
		se_comp(d, x, y);
}

void	three_ways(t_data *d, int x, int y)
{
	if (d->m->north == 1 && d->m->south == 1
		&& (d->m->west == 1 || d->m->east == 1))
		nsw_or_nse_comp(d, x, y);
	else
		wes_or_wen_comp(d, x, y);
}

void	four_ways(t_data *d, int x, int y)
{
	if (d->m->a >= x && y > d->m->b)
		move_west(d, x, y);
	else if (d->m->a <= x && y < d->m->b)
		move_east(d, x, y);
	else if (d->m->b >= y && x < d->m->a)
		move_south(d, x, y);
	else if (d->m->b <= y && x > d->m->a)
		move_north(d, x, y);
	else
		move_west(d, x, y);
}
