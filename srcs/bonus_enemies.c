/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:32:37 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/09 13:43:28 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ennemies(t_data *d, int x, int y, t_mlx *m)
{
	if (d->w->map[x][y] == '1')
		return ;
	m->img = mlx_xpm_file_to_image(m->mlx, "./textures/bonus/S2PS.xpm", &m->x, &m->y);
	mlx_put_image_to_window(m->mlx, m->win, m->img, x * 32, y * 32);
	flood_fill(d, x, y + 1);
	flood_fill(d, x - 1, y);
	flood_fill(d, x, y - 1);
	flood_fill(d, x + 1, y);
	return ;
}

void	way_ennemies(char **tab, t_data *d, t_mlx *m)
{
	int	x;
	int	y;

	d->w->map = tab;
	x = 3;
	y = 4;
	ennemies(d, x, y, m);
}
