/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_ways_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:06:55 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/17 17:35:14 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void two_ways(t_data *d, int x, int y)
{
	if ((d->m->north == 1 && d->m->south == 1) 
		|| (d->m->west == 1 && d->m->est == 1))
		ns_comp(d, x, y);
	if (d->m->north == 1 && d->m->west == 1)
	if (d->m->north == 1 && d->m->est == 1)
	if (d->m->south == 1 && d->m->west == 1)
	if (d->m->south == 1 && d->m->est == 1)
}

void	ns_or_we_comp(t_data *d, int x, int y)
{
	if (d->m->north == 1 && d->m->south == 1)
	{
		if(d->m->a > y)
			move_south(d, x, y);
		else
			move_north(d, x, y);
	}
	else if (d->m->west == 1 && d->m->est == 1)
	{
		if(d->m->a > x)
			move_est(d, x, y);
		else
			move_west(d, x, y);
	}
}
