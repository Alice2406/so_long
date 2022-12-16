/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:37:56 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/16 12:31:36 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_font(t_data *d, int digit, int i, int height)
{
	int	width;

	width = d->s->width * 32;
	if (digit == 0)
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->f->zer, height, width);
	if (digit == 1)
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->f->one, height, width);
	if (digit == 2)
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->f->two, height, width);
	if (digit == 3)
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->f->thr, height, width);
	if (digit == 4)
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->f->fou, height, width);
	if (digit == 5)
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->f->fiv, height, width);
	if (digit == 6)
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->f->six, height, width);
	if (digit == 7)
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->f->sev, height, width);
	if (digit == 8)
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->f->eig, height, width);
	if (digit == 9)
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->f->nin, height, width);
}

void	ft_update_score(t_data *d, int score)
{
	int	i;
	int	height;
	int	digit;

	i = 0;
	while (i < 4)
	{
		height = (d->s->height - 2 - i) * 32;
		digit = score % 10;
		score /= 10;
		mlx_put_image_to_window(d->m->mlx, d->m->win,
			d->f->zer, height, d->s->width * 32);
		ft_put_font(d, digit, i, height);
		i++;
	}
}
