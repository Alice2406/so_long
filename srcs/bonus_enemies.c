/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:32:37 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/10 17:53:55 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	move_4(t_bonus *game, int x, int y, t_mlx *m)
// {
// 	int		i;
// 	int		j;
// 	void	*img;

// 	while (m->tab[y][x + 1] != '1')
// 	{
// 		img = mlx_xpm_file_to_image(m->mlx, "./textures/terrain.xpm", &m->x, &m->y);
// 		mlx_put_image_to_window(m->mlx, m->win, img, x * 32, y * 32);
// 		m->tab[y][x] = '0';
// 		m->tab[y][x -1] = 'N';
// 		i = y * 32;
// 		j = (x * 32) - 32;
// 		img = mlx_xpm_file_to_image(m->mlx, "./textures/bonus/S2PA.xpm", &m->x, &m->y);
// 		mlx_put_image_to_window(m->mlx, m->win, img, j * 32, i * 32);
// 		x++;
// 	}	
// }

// void	move_2(t_bonus *game, int x, int y, t_mlx *m)
// {
// 	int		i;
// 	int		j;
// 	void	*img;

// 	if (x == m->a && y == m->b)
// 		ft_printf("touch by the ennemies\n");
// 	if (m->tab[y][x - 1] != '1')
// 	{
// 		img = mlx_xpm_file_to_image(m->mlx, "./textures/terrain.xpm", &m->x, &m->y);
// 		mlx_put_image_to_window(m->mlx, m->win, img, x * 32, y * 32);
// 		m->tab[y][x] = '0';
// 		m->tab[y][x -1] = 'N';
// 		i = y * 32;
// 		j = (x * 32) - 32;
// 		img = mlx_xpm_file_to_image(m->mlx, "./textures/bonus/S2PA.xpm", &m->x, &m->y);
// 		mlx_put_image_to_window(m->mlx, m->win, img, j * 32, i * 32);
// 	}
// 	else if (m->tab[y][x + 1] == '0')
// 		move_4(game, x, y, m);
// }

void	move_anim(t_bonus *game, t_data *d, t_mlx *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->s->width)
	{
		j = 0;
		while (j < d->s->height)
		{
			if (m->tab[i][j] == 'N')
				ft_printf("hello\n");
//				move_2(game, j, i, m);
			j++;
		}
		i++;
	}
}

int	anim(t_mlx *m)
{
	m->enemyspeed++;
	if (m->enemyspeed >= 3000)
	{
		ft_printf("hello\n");
//		move_anim(game, d, m);
		m->enemyspeed = 0;
	}
	return (0);
}
