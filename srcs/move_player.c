/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:54:22 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/22 17:55:26 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_place(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	d->m->a = -1;
	while (d->m->tab[i] && d->m->a == -1)
	{
		j = 0;
		while (d->m->tab[i][j] && d->m->a == -1)
		{
			if (d->m->tab[i][j] == 'P')
			{
				d->m->a = i;
				d->m->b = j;
			}
			j++;
		}
		i++;
	}
}

void	print_img_move(t_data *d)
{
	if (d->m->tab[d->m->a][d->m->b] == 'E')
	{
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, DOOR, &d->m->x, &d->m->y);
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, d->m->b * 32, d->m->a * 32);
	}
	else
	{
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, d->m->b * 32, d->m->a * 32);
	}
}

void	move_back_or_front(t_data *d)
{
	if ((d->m->key == S && d->m->tab[d->m->a + 1][d->m->b] != '1')
		|| (d->m->key == W && d->m->tab[d->m->a - 1][d->m->b] != '1'))
	{
		print_img_move(d);
		if (d->m->key == S)
		{
			d->m->a += 1;
			d->m->img = mlx_xpm_file_to_image(d->m->mlx, FIRE, &d->m->x, &d->m->y);
		}
		else
		{
			d->m->a -= 1;
			d->m->img = mlx_xpm_file_to_image(d->m->mlx, FIRE, &d->m->x, &d->m->y);
		}
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, d->m->b * 32, d->m->a * 32);
	}
	if (d->m->tab[d->m->a][d->m->b] == 'C')
		d->m->tab[d->m->a][d->m->b] = '0';
	if (d->m->tab[d->m->a][d->m->b] == 'E' && check_tab(d) == 0)
	{
		ft_printf("WIIIIIIIINNER\n");
		exit(0);
	}
}

void	move_right_or_left(t_data *d)
{
	if ((d->m->key == D && d->m->tab[d->m->a][d->m->b + 1] != '1')
		|| (d->m->key == A && d->m->tab[d->m->a][d->m->b - 1] != '1'))
	{
		print_img_move(d);
		if (d->m->key == D)
		{
			d->m->b += 1;
			d->m->img = mlx_xpm_file_to_image(d->m->mlx, FIRE, &d->m->x, &d->m->y);
		}
		else
		{
			d->m->b -= 1;
			d->m->img = mlx_xpm_file_to_image(d->m->mlx, FIRE, &d->m->x, &d->m->y);
		}
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, d->m->b * 32, d->m->a * 32);
	}
	if (d->m->tab[d->m->a][d->m->b] == 'C')
		d->m->tab[d->m->a][d->m->b] = '0';
	if (d->m->tab[d->m->a][d->m->b] == 'E' && check_tab(d) == 0)
	{
		ft_printf("WIIIIIIIINNER\n");
		exit(0);
	}
}

void	move_player(t_data *d)
{
	if (d->m->key == D || d->m->key == A)
		move_right_or_left(d);
	else if (d->m->key == S || d->m->key == W)
		move_back_or_front(d);
}
