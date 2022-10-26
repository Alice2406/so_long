/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:54:22 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/26 13:04:17 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_place(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	data->a = -1;
	while (data->tab[i] && data->a == -1)
	{
		j = 0;
		while (data->tab[i][j] && data->a == -1)
		{
			if (data->tab[i][j] == 'P')
			{
				data->a = i;
				data->b = j;
			}
			j++;
		}
		i++;
	}
}

void	print_img_move(t_data *d)
{
	if (d->tab[d->a][d->b] == 'E')
	{
		d->img = mlx_xpm_file_to_image(d->mlx, DOOR, &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->img, d->b * 32, d->a * 32);
	}
	else
	{
		d->img = mlx_xpm_file_to_image(d->mlx, TERRAIN, &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->img, d->b * 32, d->a * 32);
	}
}

void	move_back_or_front(t_data *d)
{
	if ((d->key == S && d->tab[d->a + 1][d->b] != '1')
		|| (d->key == W && d->tab[d->a - 1][d->b] != '1'))
	{
		if (((d->tab[d->a + 1][d->b] == 'C' && d->key == S)
			|| (d->tab[d->a - 1][d->b] == 'C' && d->key == W)) && d->bomb != 0)
			d->bomb--;
		print_img_move(d);
		if (d->key == S)
			d->a += 1;
		else
			d->a -= 1;
		d->img = mlx_xpm_file_to_image(d->mlx, FIRE, &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->img, d->b * 32, d->a * 32);
	}
	ft_printf("bomb : %d\n", d->bomb);
	if (d->tab[d->a][d->b] == 'E' && d->bomb == 0)
		exit(0);
}

void	move_right_or_left(t_data *d)
{
	if ((d->key == D && d->tab[d->a][d->b + 1] != '1')
		|| (d->key == A && d->tab[d->a][d->b - 1] != '1'))
	{
		if (((d->tab[d->a][d->b + 1] == 'C' && d->key == D)
			|| (d->tab[d->a][d->b - 1] == 'C' && d->key == A)) && d->bomb != 0)
			d->bomb--;
		print_img_move(d);
		if (d->key == D)
			d->b += 1;
		else
			d->b -= 1;
		d->img = mlx_xpm_file_to_image(d->mlx, FIRE, &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->img, d->b * 32, d->a * 32);
	}
	ft_printf("bomb : %d\n", d->bomb);
	if (d->tab[d->a][d->b] == 'E' && d->bomb == 0)
		exit(0);
}

void	move_player(t_data *data)
{
	if (data->key == D || data->key == A)
		move_right_or_left(data);
	else if (data->key == S || data->key == W)
		move_back_or_front(data);
}
