/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:32:11 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/15 18:30:43 by aniezgod         ###   ########.fr       */
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
	d->error->enemy = 0;
}

void	way_init(t_data *d)
{
	d->w->exit = 0;
	d->w->bomb = 0;
	d->w->tbomb = 0;
	d->w->x = 0;
	d->w->y = 0;
}

void	init_mlx(t_data *d)
{
	d->m->mlx = NULL;
	d->m->win = NULL;
	d->m->img = NULL;
	d->m->x = 0;
	d->m->y = 0;
	d->m->a = 0;
	d->m->b = 0;
	d->m->key = 0;
	d->m->tab = NULL;
	d->m->enemyspeed = 0;
	d->m->north = 0;
	d->m->south = 0;
	d->m->west = 0;
	d->m->east = 0;
	d->m->nb_way = 0;
	d->m->life = 1;
	d->m->enemy = 0;
}

t_data	*data_init(void)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (!d)
		return (NULL);
	d->s = malloc(sizeof(t_map));
	d->error = malloc(sizeof(t_error));
	d->w = malloc(sizeof(t_way));
	d->m = malloc(sizeof(t_mlx));
	d->t = malloc(sizeof(t_sprite));
	d->p = malloc(sizeof(t_player));
	d->e = malloc(sizeof(t_enemy));
	d->f = malloc(sizeof(t_font));
	if (!d->s || !d->error || !d->w || !d->m || !d->t
		|| !d->p || !d->e || !d->f)
		return (NULL);
	map_init(d);
	error_init(d);
	way_init(d);
	init_mlx(d);
	init_sprite(d);
	init_player(d);
	init_enemy(d);
	init_font(d);
	return (d);
}
