/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:09:18 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/15 18:41:20 by aniezgod         ###   ########.fr       */
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

void	player_bonus(t_data *d)
{
	d->p->a_one = mlx_xpm_file_to_image(d->m->mlx, AONE, &d->m->x, &d->m->y);
	d->p->d_one = mlx_xpm_file_to_image(d->m->mlx, DONE, &d->m->x, &d->m->y);
	d->p->w_one = mlx_xpm_file_to_image(d->m->mlx, WONE, &d->m->x, &d->m->y);
	d->p->s_one = mlx_xpm_file_to_image(d->m->mlx, SONE, &d->m->x, &d->m->y);
	d->p->a_two = mlx_xpm_file_to_image(d->m->mlx, ATWO, &d->m->x, &d->m->y);
	d->p->d_two = mlx_xpm_file_to_image(d->m->mlx, DTWO, &d->m->x, &d->m->y);
	d->p->w_two = mlx_xpm_file_to_image(d->m->mlx, WTWO, &d->m->x, &d->m->y);
	d->p->s_two = mlx_xpm_file_to_image(d->m->mlx, STWO, &d->m->x, &d->m->y);
	d->p->a_three = mlx_xpm_file_to_image(d->m->mlx, ATHREE, &d->m->x, &d->m->y);
	d->p->d_three = mlx_xpm_file_to_image(d->m->mlx, DTHREE, &d->m->x, &d->m->y);
	d->p->w_three = mlx_xpm_file_to_image(d->m->mlx, WTHREE, &d->m->x, &d->m->y);
	d->p->s_three = mlx_xpm_file_to_image(d->m->mlx, STHREE, &d->m->x, &d->m->y);
}

