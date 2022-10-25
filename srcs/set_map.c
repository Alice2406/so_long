/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:12:28 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/25 18:19:56 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	init_data(void)
{
	t_data	data;

	data.x = 0;
	data.y = 0;
	data.bits_per_pixel = 0;
	data.endian = 0;
	data.line_length = 0;
	data.a = 0;
	data.b = 0;
	data.key = 0;
	return (data);
}

static int	putstr_key(int key, t_data *data)
{
	data->key = key;
	if (key == 100 || key == 97 || key == 119 || key == 115)
		move_player(data);
	return (0);
}

void	set_map(t_data *data, char **tab, int x, int y)
{
	*data = init_data();

	data->tab = tab;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (x * 32), (y * 32), "so_long");
	item_location(data, tab);
	player_place(data);
	mlx_key_hook(data->win, putstr_key, data);
	mlx_loop(data->mlx);
}

void	item_location(t_data *data, char **tab)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			c = tab[i][j];
			show_map(data, tab[i][j]);
			data->a += 32;
			j++;
		}
		data->a = 0;
		data->b += 32;
		i++;
	}
}

void	show_map(t_data *d, char c)
{
	if (c == '1')
		d->img = mlx_xpm_file_to_image(d->mlx, WALL, &d->x, &d->y);
	else if (c== '0')
		d->img = mlx_xpm_file_to_image(d->mlx, TERRAIN, &d->x, &d->y);
	else if (c == 'P')
		d->img = mlx_xpm_file_to_image(d->mlx, FIRE, &d->x, &d->y);
	else if (c == 'C')
		d->img = mlx_xpm_file_to_image(d->mlx, BOMB, &d->x, &d->y);
	else
		d->img = mlx_xpm_file_to_image(d->mlx, DOOR, &d->x, &d->y);
	mlx_put_image_to_window(d->mlx, d->win, d->img, d->a, d->b);
}

//nb case x 32

// d key = 100
// a key = 97
// w key = 119
// s key = 115