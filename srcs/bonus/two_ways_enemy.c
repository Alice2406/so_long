/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_ways_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:06:55 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/09 16:19:11 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ns_or_we_comp(t_data *d, int x, int y)
{
	if (d->m->north == 1 && d->m->south == 1)
	{
		if (d->m->a > x)
			move_south(d, x, y);
		else
			move_north(d, x, y);
	}
	else
	{
		if (d->m->b > y)
			move_east(d, x, y);
		else
			move_west(d, x, y);
	}
}

void	nw_comp(t_data *d, int x, int y)
{
	if (d->m->a == x && y > d->m->b)
		move_west(d, x, y);
	else if (d->m->a == x)
		move_north(d, x, y);
	else if (d->m->b == y && x > d->m->a)
		move_north(d, x, y);
	else if (d->m->b == y)
		move_west(d, x, y);
	else if ((d->m->a - x) > (d->m->b - y))
		move_north(d, x, y);
	else
		move_west(d, x, y);
}

void	ne_comp(t_data *d, int x, int y)
{
	if (d->m->a == x && y < d->m->b)
		move_east(d, x, y);
	else if (d->m->a == x)
		move_north(d, x, y);
	else if (d->m->b == y && x > d->m->a)
		move_north(d, x, y);
	else if (d->m->b == y)
		move_east(d, x, y);
	else if ((d->m->a - x) > (d->m->b - y))
		move_north(d, x, y);
	else
		move_east(d, x, y);
}

void	sw_comp(t_data *d, int x, int y)
{
	if (d->m->a == x && y > d->m->b)
		move_west(d, x, y);
	else if (d->m->a == x)
		move_south(d, x, y);
	else if (d->m->b == y && x < d->m->a)
		move_south(d, x, y);
	else if (d->m->b == y)
		move_west(d, x, y);
	else if ((d->m->a - x) > (d->m->b - y))
		move_south(d, x, y);
	else
		move_west(d, x, y);
}

void	se_comp(t_data *d, int x, int y)
{
	if (d->m->a == x && y < d->m->b)
		move_east(d, x, y);
	else if (d->m->a == x)
		move_south(d, x, y);
	else if (d->m->b == y && x < d->m->a)
		move_south(d, x, y);
	else if (d->m->b == y)
		move_east(d, x, y);
	else if ((d->m->a - x) > (d->m->b - y))
		move_south(d, x, y);
	else
		move_east(d, x, y);
}
