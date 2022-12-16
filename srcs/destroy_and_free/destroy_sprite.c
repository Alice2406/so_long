/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:11:06 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/16 13:35:07 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_sprite(t_data *d)
{
	mlx_destroy_image(d->m->mlx, d->t->wall);
	mlx_destroy_image(d->m->mlx, d->t->door);
	mlx_destroy_image(d->m->mlx, d->t->sol);
	mlx_destroy_image(d->m->mlx, d->t->bomb);
	mlx_destroy_image(d->m->mlx, d->t->fire);
}

void	destroy_player(t_data *d)
{
	mlx_destroy_image(d->m->mlx, d->p->a_one);
	mlx_destroy_image(d->m->mlx, d->p->d_one);
	mlx_destroy_image(d->m->mlx, d->p->w_one);
	mlx_destroy_image(d->m->mlx, d->p->s_one);
	mlx_destroy_image(d->m->mlx, d->p->a_two);
	mlx_destroy_image(d->m->mlx, d->p->d_two);
	mlx_destroy_image(d->m->mlx, d->p->w_two);
	mlx_destroy_image(d->m->mlx, d->p->s_two);
	mlx_destroy_image(d->m->mlx, d->p->a_three);
	mlx_destroy_image(d->m->mlx, d->p->d_three);
	mlx_destroy_image(d->m->mlx, d->p->w_three);
	mlx_destroy_image(d->m->mlx, d->p->s_three);
}

void	destroy_enemy(t_data *d)
{
	mlx_destroy_image(d->m->mlx, d->e->es);
	mlx_destroy_image(d->m->mlx, d->e->ea);
	mlx_destroy_image(d->m->mlx, d->e->ew);
	mlx_destroy_image(d->m->mlx, d->e->ed);
}

void	destroy_font(t_data *d)
{
	mlx_destroy_image(d->m->mlx, d->f->zer);
	mlx_destroy_image(d->m->mlx, d->f->one);
	mlx_destroy_image(d->m->mlx, d->f->two);
	mlx_destroy_image(d->m->mlx, d->f->thr);
	mlx_destroy_image(d->m->mlx, d->f->fou);
	mlx_destroy_image(d->m->mlx, d->f->fiv);
	mlx_destroy_image(d->m->mlx, d->f->six);
	mlx_destroy_image(d->m->mlx, d->f->sev);
	mlx_destroy_image(d->m->mlx, d->f->eig);
	mlx_destroy_image(d->m->mlx, d->f->nin);
	mlx_destroy_image(d->m->mlx, d->f->full);
	mlx_destroy_image(d->m->mlx, d->f->empty);
}
