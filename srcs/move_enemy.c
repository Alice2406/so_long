/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:15:07 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/23 16:02:51 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_bomb_door(t_data *d, int x, int y)
{
	if (d->s->door == 1)
	{
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, DOOR, &d->m->x, &d->m->y);
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, y * 32, x * 32);
		d->m->tab[x][y] = 'E';		
	}
	else if (d->s->bomb == 1)
	{
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, BOMB, &d->m->x, &d->m->y);
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, y * 32, x * 32);
		d->m->tab[x][y] = 'C';		
	}
	d->s->door = 0;
	d->s->bomb = 0;
}
void	move_north(t_data *d, int x, int y)
{
	int i;
	int j;

	if (d->s->door != 1 && d->s->bomb != 1)
	{
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, y * 32, x * 32);
		d->m->tab[x][y] = '0';
	}
	else
		enemy_bomb_door(d, x, y);
	if (d->m->tab[x - 1][y] == 'C')
		d->s->bomb = 1;
	if (d->m->tab[x - 1][y] == 'E')
		d->s->door = 1;
	d->m->tab[x - 1][y] = 'N';
	i = (x * 32) - 32;
	j = y * 32;
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, "./textures/bonus/ESW.xpm", &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, j, i);
	if (d->m->a == x && d->m->b == y)
		d->m->life--;
	if (d->m->life == 0)
	{
		ft_printf("LOOOOOOOOSER\n");
		destroy_window(d);
	}
}

void	move_south(t_data *d, int x, int y)
{
	int i;
	int j;

	if (d->s->door != 1 && d->s->bomb != 1)
	{
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, y * 32, x * 32);
		d->m->tab[x][y] = '0';
	}
	else
		enemy_bomb_door(d, x, y);
	if (d->m->tab[x + 1][y] == 'C')
		d->s->bomb = 1;
	if (d->m->tab[x + 1][y] == 'E')
		d->s->door = 1;
	d->m->tab[x + 1][y] = 'N';
	i = (x * 32) + 32;
	j = y * 32;
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, "./textures/bonus/ESS.xpm", &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, j, i);
	if (d->m->a == x && d->m->b == y)
		d->m->life--;
	if (d->m->life == 0)
	{
		ft_printf("LOOOOOOOOSER\n");
		destroy_window(d);
	}
}

void	move_west(t_data *d, int x, int y)
{
	int i;
	int j;
	
	if (d->s->door != 1 && d->s->bomb != 1)
	{
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, y * 32, x * 32);
		d->m->tab[x][y] = '0';
	}
	else
		enemy_bomb_door(d, x, y);
	if (d->m->tab[x][y - 1] == 'C')
		d->s->bomb = 1;
	if (d->m->tab[x][y - 1] == 'E')
		d->s->door = 1;
	d->m->tab[x][y - 1] = 'N';
	i = x * 32;
	j = (y * 32) - 32;
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, "./textures/bonus/ESA.xpm", &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, j, i);
	if (d->m->a == x && d->m->b == y)
		d->m->life--;
	if (d->m->life == 0)
	{
		ft_printf("LOOOOOOOOSER\n");
		destroy_window(d);
	}
}

void move_east(t_data *d, int x, int y)
{
	int i;
	int j;
	
	if (d->s->door != 1 && d->s->bomb != 1)
	{
		d->m->img = mlx_xpm_file_to_image(d->m->mlx, SOL, &d->m->x, &d->m->y);
		mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, y * 32, x * 32);
		d->m->tab[x][y] = '0';
	}
	else
		enemy_bomb_door(d, x, y);
	if (d->m->tab[x][y + 1] == 'C')
		d->s->bomb = 1;
	if (d->m->tab[x][y + 1] == 'E')
		d->s->door = 1;
	d->m->tab[x][y + 1] = 'N';
	i = x * 32;
	j = (y * 32) + 32;
	d->m->img = mlx_xpm_file_to_image(d->m->mlx, "./textures/bonus/ESD.xpm", &d->m->x, &d->m->y);
	mlx_put_image_to_window(d->m->mlx, d->m->win, d->m->img, j, i);
	if (d->m->a == x && d->m->b == y)
		d->m->life--;
	if (d->m->life == 0)
	{
		ft_printf("LOOOOOOOOSER\n");
		destroy_window(d);
	}
}
//faire perdre de la vie au player si l'ennemi et le player se rencontre -> mettre le player au stade inferieur et si playeur boule -> mort du perso !