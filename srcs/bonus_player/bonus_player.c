/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:55:08 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/16 15:53:00 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_back_or_front_one(t_data *d)
{
	if ((d->m->key == S && d->m->tab[d->m->a + 1][d->m->b] != '1')
		|| (d->m->key == W && d->m->tab[d->m->a - 1][d->m->b] != '1'))
	{
		print_move(d);
		print_img_move(d);
		if (d->m->key == S)
		{
			d->m->a += 1;
			mlx_put_image_to_window(d->m->mlx, d->m->win, d->p->s_one,
				d->m->b * 32, d->m->a * 32);
		}
		else
		{
			d->m->a -= 1;
			mlx_put_image_to_window(d->m->mlx, d->m->win, d->p->w_one,
				d->m->b * 32, d->m->a * 32);
		}
	}
	if (d->m->tab[d->m->a][d->m->b] == 'C')
		d->m->tab[d->m->a][d->m->b] = '0';
	if (d->m->tab[d->m->a][d->m->b] == 'E' && check_tab(d) == 0)
		ft_exit(d, 2);
}

void	move_right_or_left_one(t_data *d)
{
	if ((d->m->key == D && d->m->tab[d->m->a][d->m->b + 1] != '1')
		|| (d->m->key == A && d->m->tab[d->m->a][d->m->b - 1] != '1'))
	{
		print_move(d);
		print_img_move(d);
		if (d->m->key == D)
		{
			d->m->b += 1;
			mlx_put_image_to_window(d->m->mlx, d->m->win, d->p->d_one,
				d->m->b * 32, d->m->a * 32);
		}
		else
		{
			d->m->b -= 1;
			mlx_put_image_to_window(d->m->mlx, d->m->win, d->p->a_one,
				d->m->b * 32, d->m->a * 32);
		}
	}
	if (d->m->tab[d->m->a][d->m->b] == 'C')
		d->m->tab[d->m->a][d->m->b] = '0';
	if (d->m->tab[d->m->a][d->m->b] == 'E' && check_tab(d) == 0)
		ft_exit(d, 2);
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
	if (d->m->tab[d->m->a][d->m->b] == 'N' && d->m->life > 0)
		d->m->life--;
	if (d->m->life == 0)
		ft_exit(d, 1);
	check_life(d);
	show_heart(d->m->life, d);
	if (d->m->life == 1 && (d->m->key == D || d->m->key == A))
		move_right_or_left_one(d);
	else if (d->m->life == 1 && (d->m->key == S || d->m->key == W))
		move_back_or_front_one(d);
	else if (d->m->life == 2 && (d->m->key == D || d->m->key == A))
		move_right_or_left_two(d);
	else if (d->m->life == 2 && (d->m->key == S || d->m->key == W))
		move_back_or_front_two(d);
	else if (d->m->life == 3 && (d->m->key == D || d->m->key == A))
		move_right_or_left_three(d);
	else if (d->m->life == 3 && (d->m->key == S || d->m->key == W))
		move_back_or_front_three(d);
}
