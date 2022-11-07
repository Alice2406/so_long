/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:32:11 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/07 15:21:25 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_data *d)
{
	d->s->height = 0;
	d->s->width = 0;
	d->s->player = 0;
	d->s->door = 0;
	d->s->bomb = 0;
}

void	error_init(t_data *d)
{
	d->error->exit = 0;
	d->error->player = 0;
	d->error->bomb = 0;
	d->error->char_map = 0;
	d->error->shape = 0;
	d->error->wall = 0;
	d->error->way = 0;
}

void	way_init(t_data *d)
{
	d->w->map = NULL;
	d->w->exit = 0;
	d->w->bomb = 0;
	d->w->tbomb = 0;
	d->w->x = 0;
	d->w->y = 0;
}

t_data	*data_init(void)
{
	t_data	*d;

	d = malloc(sizeof(d));
	if (!d)
		return (NULL);
	d->s = malloc(sizeof(t_map));
	d->error = malloc(sizeof(t_error));
	d->w = malloc(sizeof(t_way));
	if (!d->s || !d->error || !d->w)
		return (NULL);
	map_init(d);
	error_init(d);
	way_init(d);
	return (d);
}
