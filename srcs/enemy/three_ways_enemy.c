/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_ways_enemy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:20:20 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/25 13:42:14 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	nsw_or_nse_comp(t_data *d, int x, int y)
{
	if (d->m->west == 1 && d->m->a == x && y > d->m->b)
		move_west(d, x, y);
	else if (d->m->east == 1 && d->m->a == x && y < d->m->b)
		move_east(d, x, y);
	else if ((d->m->west == 1 || d->m->east == 1) && d->m->a == x)
		move_south(d, x, y);
	else if (d->m->a > x)
		move_south(d, x, y);
	else
		move_north(d, x, y);
}

void	wes_or_wen_comp(t_data *d, int x, int y)
{
	if (d->m->south == 1 && d->m->b == y && x < d->m->a)
		move_south(d, x, y);
	else if (d->m->north == 1 && d->m->b == y && x > d->m->a)
		move_north(d, x, y);
	else if ((d->m->north == 1 || d->m->south == 1) && d->m->b == y)
		move_west(d, x, y);
	else if (d->m->b > y)
		move_east(d, x, y);
	else
		move_west(d, x, y);
}
