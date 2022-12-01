/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_player2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:46:12 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/01 16:46:25 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_heart(int i, t_data *d)
{
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, HEART_F, &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, 0, d->s->width * 32);
	if (i == 1)
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, HEART_E, &d->m->x, &d->m->y);
	else if (i == 2 || i == 3)
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, HEART_F, &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, 32, d->s->width * 32);
	if (i == 1 || i == 2)
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, HEART_E, &d->m->x, &d->m->y);
	else if (i == 3)
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, HEART_F, &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, 64, d->s->width * 32);
}

char	*stade_one(t_data *d)
{
	char	*stade;

	if (d->m->key == W)
		stade = "./textures/bonus/S1PW.xpm";
	else if (d->m->key == A)
		stade = "./textures/bonus/S1PA.xpm";
	else if (d->m->key == S)
		stade = "./textures/bonus/S1PS.xpm";
	else if (d->m->key == D)
		stade = "./textures/bonus/S1PD.xpm";
	show_heart(1, d);
	return (stade);
}

char	*stade_two(t_data *d)
{
	char	*stade;

	if (d->m->key == W)
		stade = "./textures/bonus/S2PW.xpm";
	else if (d->m->key == A)
		stade = "./textures/bonus/S2PA.xpm";
	else if (d->m->key == S)
		stade = "./textures/bonus/S2PS.xpm";
	else if (d->m->key == D)
		stade = "./textures/bonus/S2PD.xpm";
	show_heart(2, d);
	return (stade);
}

char	*stade_three(t_data *d)
{
	char	*stade;

	if (d->m->key == W)
		stade = "./textures/bonus/S3PW.xpm";
	else if (d->m->key == A)
		stade = "./textures/bonus/S3PA.xpm";
	else if (d->m->key == S)
		stade = "./textures/bonus/S3PS.xpm";
	else if (d->m->key == D)
		stade = "./textures/bonus/S3PD.xpm";
	show_heart(3, d);
	return (stade);
}