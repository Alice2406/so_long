/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_player2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:46:12 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/16 13:05:02 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_heart(int i, t_data *d)
{	
	int	width;

	if (d->s->height > 7)
		width = d->s->width;
	else
		width = d->s->width + 1;
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->f->full, 0, width * 32);
	if (i == 1)
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->f->empty,
			32, width * 32);
	else if (i == 2 || i == 3)
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->f->full,
			32, width * 32);
	if (i == 1 || i == 2)
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->f->empty,
			64, width * 32);
	else if (i == 3)
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->f->full,
			64, width * 32);
}

void	move_back_or_front_two(t_data *d)
{
	if ((d->m->key == S && d->m->tab[d->m->a + 1][d->m->b] != '1')
		|| (d->m->key == W && d->m->tab[d->m->a - 1][d->m->b] != '1'))
	{
		print_move(d);
		print_img_move(d);
		if (d->m->key == S)
		{
			d->m->a += 1;
			mlx_put_image_to_window(d->m->mlx, d->m->win, d->p->s_two,
				d->m->b * 32, d->m->a * 32);
		}
		else
		{
			d->m->a -= 1;
			mlx_put_image_to_window(d->m->mlx, d->m->win, d->p->w_two,
				d->m->b * 32, d->m->a * 32);
		}
	}
	if (d->m->tab[d->m->a][d->m->b] == 'C')
		d->m->tab[d->m->a][d->m->b] = '0';
	if (d->m->tab[d->m->a][d->m->b] == 'E' && check_tab(d) == 0)
		ft_exit(d);
}

void	move_right_or_left_two(t_data *d)
{
	if ((d->m->key == D && d->m->tab[d->m->a][d->m->b + 1] != '1')
		|| (d->m->key == A && d->m->tab[d->m->a][d->m->b - 1] != '1'))
	{
		print_move(d);
		print_img_move(d);
		if (d->m->key == D)
		{
			d->m->b += 1;
			mlx_put_image_to_window(d->m->mlx, d->m->win, d->p->d_two,
				d->m->b * 32, d->m->a * 32);
		}
		else
		{
			d->m->b -= 1;
			mlx_put_image_to_window(d->m->mlx, d->m->win, d->p->a_two,
				d->m->b * 32, d->m->a * 32);
		}
	}
	if (d->m->tab[d->m->a][d->m->b] == 'C')
		d->m->tab[d->m->a][d->m->b] = '0';
	if (d->m->tab[d->m->a][d->m->b] == 'E' && check_tab(d) == 0)
		ft_exit(d);
}

void	move_back_or_front_three(t_data *d)
{
	if ((d->m->key == S && d->m->tab[d->m->a + 1][d->m->b] != '1')
		|| (d->m->key == W && d->m->tab[d->m->a - 1][d->m->b] != '1'))
	{
		print_move(d);
		print_img_move(d);
		if (d->m->key == S)
		{
			d->m->a += 1;
			mlx_put_image_to_window(d->m->mlx, d->m->win, d->p->s_three,
				d->m->b * 32, d->m->a * 32);
		}
		else
		{
			d->m->a -= 1;
			mlx_put_image_to_window(d->m->mlx, d->m->win, d->p->w_three,
				d->m->b * 32, d->m->a * 32);
		}
	}
	if (d->m->tab[d->m->a][d->m->b] == 'C')
		d->m->tab[d->m->a][d->m->b] = '0';
	if (d->m->tab[d->m->a][d->m->b] == 'E' && check_tab(d) == 0)
		ft_exit(d);
}

void	move_right_or_left_three(t_data *d)
{
	if ((d->m->key == D && d->m->tab[d->m->a][d->m->b + 1] != '1')
		|| (d->m->key == A && d->m->tab[d->m->a][d->m->b - 1] != '1'))
	{
		print_move(d);
		print_img_move(d);
		if (d->m->key == D)
		{
			d->m->b += 1;
			mlx_put_image_to_window(d->m->mlx, d->m->win, d->p->d_three,
				d->m->b * 32, d->m->a * 32);
		}
		else
		{
			d->m->b -= 1;
			mlx_put_image_to_window(d->m->mlx, d->m->win, d->p->a_three,
				d->m->b * 32, d->m->a * 32);
		}
	}
	if (d->m->tab[d->m->a][d->m->b] == 'C')
		d->m->tab[d->m->a][d->m->b] = '0';
	if (d->m->tab[d->m->a][d->m->b] == 'E' && check_tab(d) == 0)
		ft_exit(d);
}
