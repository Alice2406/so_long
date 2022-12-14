/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:55:08 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/14 18:21:14 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_back_or_front_bonus(t_data *d, char *stade)
{
	if ((d->m->key == S && d->m->tab[d->m->a + 1][d->m->b] != '1')
		|| (d->m->key == W && d->m->tab[d->m->a - 1][d->m->b] != '1'))
	{
		print_move(d);
		print_img_move(d);
		if (d->m->key == S)
		{
			d->m->a += 1;
			d->m->img = mlx_xpm_file_to_image(d->m->mlx, stade,
					&d->m->x, &d->m->y);
		}
		else
		{
			d->m->a -= 1;
			d->m->img = mlx_xpm_file_to_image(d->m->mlx, stade,
					&d->m->x, &d->m->y);
		}
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img,
			d->m->b * 32, d->m->a * 32);
	}
	if (d->m->tab[d->m->a][d->m->b] == 'C')
		d->m->tab[d->m->a][d->m->b] = '0';
	if (d->m->tab[d->m->a][d->m->b] == 'E' && check_tab(d) == 0)
		exit(0);
}

void	move_right_or_left_bonus(t_data *d, char *stade)
{
	if ((d->m->key == D && d->m->tab[d->m->a][d->m->b + 1] != '1')
		|| (d->m->key == A && d->m->tab[d->m->a][d->m->b - 1] != '1'))
	{
		print_move(d);
		print_img_move(d);
		if (d->m->key == D)
		{
			d->m->b += 1;
			d->m->img = mlx_xpm_file_to_image(d->m->mlx, stade,
					&d->m->x, &d->m->y);
		}
		else
		{
			d->m->b -= 1;
			d->m->img = mlx_xpm_file_to_image(d->m->mlx, stade,
					&d->m->x, &d->m->y);
		}
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img,
			d->m->b * 32, d->m->a * 32);
	}
	if (d->m->tab[d->m->a][d->m->b] == 'C')
		d->m->tab[d->m->a][d->m->b] = '0';
	if (d->m->tab[d->m->a][d->m->b] == 'E' && check_tab(d) == 0)
		exit(0);
}

void	check_life(t_data *d)
{
	if (d->m->life < 3 && d->m->key == D
		&& d->m->tab[d->m->a][d->m->b + 1] == 'C')
		d->m->life++;
	else if (d->m->life < 3 && d->m->key == A
		&& d->m->tab[d->m->a][d->m->b - 1] == 'C')
		d->m->life++;
	else if (d->m->life < 3 && d->m->key == S
		&& d->m->tab[d->m->a + 1][d->m->b] == 'C')
		d->m->life++;
	else if (d->m->life < 3 && d->m->key == W
		&& d->m->tab[d->m->a - 1][d->m->b] == 'C')
		d->m->life++;
}

void	move_player_bonus(t_data *d)
{
	char	*stade;

	if (d->m->tab[d->m->a][d->m->b] == 'N' && d->m->life > 0)
		d->m->life--;
	if (d->m->life == 0)
		close_window(d);
	check_life(d);
	if (d->m->life == 1)
		stade = stade_one(d);
	else if (d->m->life == 2)
		stade = stade_two(d);
	else if (d->m->life == 3)
		stade = stade_three(d);
	if (d->m->key == D || d->m->key == A)
		move_right_or_left_bonus(d, stade);
	else if (d->m->key == S || d->m->key == W)
		move_back_or_front_bonus(d, stade);
}
