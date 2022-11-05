/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:32:11 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/05 12:09:07 by aniezgod         ###   ########.fr       */
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

t_data	*data_init(void)
{
	t_data	*d;
	
	d = malloc(sizeof(d));
	if (!d)
		return (NULL);
	d->s = malloc(sizeof(t_map));
	if (!d->s)
		return (NULL);
	d->error = malloc(sizeof(t_error));
	if (!d->error)
		return (NULL);
	map_init(d);
	error_init(d);
	return (d);
}