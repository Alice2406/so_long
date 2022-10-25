/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:54:22 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/25 18:22:52 by aniezgod         ###   ########.fr       */
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

void	move_back_or_front(t_data *d)
{
	char	**tab;

	tab = d->tab;
	if (d->key == S && tab[d->a + 1][d->b] != '1')
	{
		d->img = mlx_xpm_file_to_image(d->mlx, TERRAIN, &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->img, d->b * 32, d->a * 32);
		d->a += 1;
		d->img = mlx_xpm_file_to_image(d->mlx, FIRE, &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->img, d->b * 32, d->a * 32);
	}
	else if (d->key == W && tab[d->a - 1][d->b] != '1')
	{
		d->img = mlx_xpm_file_to_image(d->mlx, TERRAIN, &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->img, d->b * 32, d->a * 32);
		d->a -= 1;
		d->img = mlx_xpm_file_to_image(d->mlx, FIRE, &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->img, d->b * 32, d->a * 32);
	}
	if (tab[d->a][d->b] == 'E')
		exit(0);
}

void	move_right_or_left(t_data *d)
{
	char	**tab;

	tab = d->tab;
	if (d->key == D && tab[d->a][d->b + 1] != '1')
	{
		d->img = mlx_xpm_file_to_image(d->mlx, TERRAIN, &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->img, d->b * 32, d->a * 32);
		d->b += 1;
		d->img = mlx_xpm_file_to_image(d->mlx, FIRE, &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->img, d->b * 32, d->a * 32);
	}
	else if (d->key == A && tab[d->a][d->b - 1] != '1')
	{
		d->img = mlx_xpm_file_to_image(d->mlx, TERRAIN, &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->img, d->b * 32, d->a * 32);
		d->b -= 1;
		d->img = mlx_xpm_file_to_image(d->mlx, FIRE, &d->x, &d->y);
		mlx_put_image_to_window(d->mlx, d->win, d->img, d->b * 32, d->a * 32);
	}
	if (tab[d->a][d->b] == 'E')
		exit(0);
}

void	move_player(t_data *data)
{
	if (data->key == D || data->key == A)
		move_right_or_left(data);
	else if (data->key == S || data->key == W)
		move_back_or_front(data);
}
