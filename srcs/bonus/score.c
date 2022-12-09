/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:37:56 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/09 16:33:40 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_font(t_data *d, int digit, int i)
{
	if (digit == 0)
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, ZERO, &d->m->x, &d->m->y);
	if (digit == 1)
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, ONE, &d->m->x, &d->m->y);
	if (digit == 2)
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, TWO, &d->m->x, &d->m->y);
	if (digit == 3)
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, THREE, &d->m->x, &d->m->y);
	if (digit == 4)
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, FOUR, &d->m->x, &d->m->y);
	if (digit == 5)
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, FIVE, &d->m->x, &d->m->y);
	if (digit == 6)
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, SIX, &d->m->x, &d->m->y);
	if (digit == 7)
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, SEVEN, &d->m->x, &d->m->y);
	if (digit == 8)
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, EIGHT, &d->m->x, &d->m->y);
	if (digit == 9)
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, NINE, &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img,
		(d->s->height - i - 2) * 32, d->s->width * 32);
}

void	ft_update_score(t_data *d, int score)
{
	int	i;
	int	height;
	int	digit;

	i = 0;
	height = d->s->height - 2;
	while (i < 4)
	{
		digit = score % 10;
		score /= 10;
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, ZERO, &d->m->x, &d->m->y);
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img,
			(height - i) * 32, d->s->width * 32);
		ft_put_font(d, digit, i);
		i++;
	}
}
