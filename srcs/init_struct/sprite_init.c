/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:09:18 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/16 13:33:43 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite_to_image(t_data *d)
{
	d->t->wall = mlx_xpm_file_to_image(d->m->mlx, WALL, &d->m->x, &d->m->y);
	d->t->door = mlx_xpm_file_to_image(d->m->mlx, DOOR, &d->m->x, &d->m->y);
	d->t->sol = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
	d->t->bomb = mlx_xpm_file_to_image(d->m->mlx, BOMB, &d->m->x, &d->m->y);
	d->t->fire = mlx_xpm_file_to_image(d->m->mlx, FIRE, &d->m->x, &d->m->y);
}

void	player_bonus_img(t_data *d)
{
	d->p->a_one = mlx_xpm_file_to_image(d->m->mlx, AONE, &d->m->x, &d->m->y);
	d->p->d_one = mlx_xpm_file_to_image(d->m->mlx, DONE, &d->m->x, &d->m->y);
	d->p->w_one = mlx_xpm_file_to_image(d->m->mlx, WONE, &d->m->x, &d->m->y);
	d->p->s_one = mlx_xpm_file_to_image(d->m->mlx, SONE, &d->m->x, &d->m->y);
	d->p->a_two = mlx_xpm_file_to_image(d->m->mlx, ATWO, &d->m->x, &d->m->y);
	d->p->d_two = mlx_xpm_file_to_image(d->m->mlx, DTWO, &d->m->x, &d->m->y);
	d->p->w_two = mlx_xpm_file_to_image(d->m->mlx, WTWO, &d->m->x, &d->m->y);
	d->p->s_two = mlx_xpm_file_to_image(d->m->mlx, STWO, &d->m->x, &d->m->y);
	d->p->a_three = mlx_xpm_file_to_image(d->m->mlx,
			ATHREE, &d->m->x, &d->m->y);
	d->p->d_three = mlx_xpm_file_to_image(d->m->mlx,
			DTHREE, &d->m->x, &d->m->y);
	d->p->w_three = mlx_xpm_file_to_image(d->m->mlx,
			WTHREE, &d->m->x, &d->m->y);
	d->p->s_three = mlx_xpm_file_to_image(d->m->mlx,
			STHREE, &d->m->x, &d->m->y);
}

void	enemy_img(t_data *d)
{
	d->e->es = mlx_xpm_file_to_image(d->m->mlx, ESS, &d->m->x, &d->m->y);
	d->e->ea = mlx_xpm_file_to_image(d->m->mlx, ESA, &d->m->x, &d->m->y);
	d->e->ew = mlx_xpm_file_to_image(d->m->mlx, ESW, &d->m->x, &d->m->y);
	d->e->ed = mlx_xpm_file_to_image(d->m->mlx, ESD, &d->m->x, &d->m->y);
}

void	font_img(t_data *d)
{
	d->f->zer = mlx_xpm_file_to_image(d->m->mlx, ZERO, &d->m->x, &d->m->y);
	d->f->one = mlx_xpm_file_to_image(d->m->mlx, ONE, &d->m->x, &d->m->y);
	d->f->two = mlx_xpm_file_to_image(d->m->mlx, TWO, &d->m->x, &d->m->y);
	d->f->thr = mlx_xpm_file_to_image(d->m->mlx, THREE, &d->m->x, &d->m->y);
	d->f->fou = mlx_xpm_file_to_image(d->m->mlx, FOUR, &d->m->x, &d->m->y);
	d->f->fiv = mlx_xpm_file_to_image(d->m->mlx, FIVE, &d->m->x, &d->m->y);
	d->f->six = mlx_xpm_file_to_image(d->m->mlx, SIX, &d->m->x, &d->m->y);
	d->f->sev = mlx_xpm_file_to_image(d->m->mlx, SEVEN, &d->m->x, &d->m->y);
	d->f->eig = mlx_xpm_file_to_image(d->m->mlx, EIGHT, &d->m->x, &d->m->y);
	d->f->nin = mlx_xpm_file_to_image(d->m->mlx, NINE, &d->m->x, &d->m->y);
	d->f->full = mlx_xpm_file_to_image(d->m->mlx, FULL, &d->m->x, &d->m->y);
	d->f->empty = mlx_xpm_file_to_image(d->m->mlx, EMPTY, &d->m->x, &d->m->y);
}

void	init_all_sprite(t_data *d)
{
	sprite_to_image(d);
	if (BONUS)
	{
		player_bonus_img(d);
		enemy_img(d);
		font_img(d);
	}
}
