/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:32:37 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/18 16:49:58 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	move_4(int x, int y, t_data *d)
// {
//  	int		i;
//  	int		j;

//  	while (d->m->tab[y][x + 1] != '1')
//  	{
//  		d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
//  		mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, x * 32, y * 32);
//  		d->m->tab[y][x] = '0';
//  		d->m->tab[y][x + 1] = 'N';
//  		i = y * 32;
//  		j = (x * 32) + 32;
//  		d->m->img = mlx_xpm_file_to_image(d->m->mlx, "./textures/bonus/ESD.xpm", &d->m->x, &d->m->y);
//  		mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, j, i);
// 			x++;
//  	}
// }

// void	move_2(int x, int y, t_data *d)
// {
//  	int		i;
//  	int		j;

//  	if (x == d->m->a && y == d->m->b)
//  		ft_printf("touch by the ennemies\n");
//  	if (d->m->tab[y][x - 1] != '1')
//  	{
// 		d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
// 		mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, x * 32, y * 32);
//  		d->m->tab[y][x] = '0';
//  		d->m->tab[y][x - 1] = 'N';
//  		i = y * 32;
//  		j = (x * 32) - 32;
//  		d->m->img = mlx_xpm_file_to_image(d->m->mlx, "./textures/bonus/ESA.xpm", &d->m->x, &d->m->y);
//  		mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, j, i);
//  	}
//  	else if (d->m->tab[y][x + 1] == '0')
//  		move_4(x, y, d);
// }

void	nb_way(t_data *d, int x, int y)
{
	if (d->m->tab[x][y - 1] != '1')
	{
		d->m->west = 1;
		d->m->nb_way++;
	}
	if (d->m->tab[x][y + 1] != '1')
	{
		d->m->east = 1;
		d->m->nb_way++;
	}
	if (d->m->tab[x + 1][y] != '1')
	{
		d->m->south = 1;
		d->m->nb_way++;
	}
	if (d->m->tab[x - 1][y] != '1')
	{
		d->m->north = 1;
		d->m->nb_way++;
	}
	ft_way(d, x, y);
}

void	ft_way(t_data *d, int x, int y)
{
	if (d->m->nb_way == 1)
		one_way(d, x, y);
	else if (d->m->nb_way == 2)
		two_ways(d, x, y);
	else if (d->m->nb_way == 3)
		three_ways(d, x, y);
	// else if (d->m->nb_way == 4)
	// 	four_ways(d, x, y);
	else
		ft_printf("error nb_way\n");
//		ft_printf("x = %d\ny = %d\nx_enemy= %d\ny_enemy = %d\n", d->m->a, d->m->b, x, y);
}
void	re_init_struct(t_data *d)
{
	d->m->nb_way = 0;
	d->m->north = 0;
	d->m->south = 0;
	d->m->east = 0;
	d->m->west = 0;
}

void	move_anim(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 33)
		{
			if (d->m->tab[i][j] == 'N')
			{
//				move_2(j, i, d);
				re_init_struct(d);
				nb_way(d, i, j);
			}
			j++;
		}
		i++;
	}
}

int	anim(t_data *d)
{
	d->m->enemyspeed++;
	if (d->m->enemyspeed >= 10000)
	{
		move_anim(d);
		d->m->enemyspeed = 0;
	}
	return (0);
}
