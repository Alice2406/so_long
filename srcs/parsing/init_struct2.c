/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:06:40 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/15 18:25:56 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprite(t_data *d)
{
	d->t->wall = NULL;
	d->t->sol = NULL;
	d->t->fire = NULL;
	d->t->bomb = NULL;
	d->t->door = NULL;
}

void	init_player(t_data *d)
{
	d->p->a_one = NULL;
	d->p->d_one = NULL;
	d->p->w_one = NULL;
	d->p->s_one = NULL;
	d->p->a_two = NULL;
	d->p->d_two = NULL;
	d->p->w_two = NULL;
	d->p->s_two = NULL;
	d->p->a_three = NULL;
	d->p->d_three = NULL;
	d->p->w_three = NULL;
	d->p->s_three = NULL;
}

void	init_enemy(t_data *d)
{
	d->e->es = NULL;
	d->e->ea = NULL;
	d->e->ew = NULL;
	d->e->ed = NULL;
}

void	init_font(t_data *d)
{
	d->f->one = NULL;
	d->f->two = NULL;
	d->f->three = NULL;
	d->f->four = NULL;
	d->f->five = NULL;
	d->f->six = NULL;
	d->f->seven = NULL;
	d->f->eight = NULL;
	d->f->nine = NULL;
	d->f->full_heart = NULL;
	d->f->empty_heart = NULL;
}