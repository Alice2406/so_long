/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:54:22 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/28 11:52:43 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_place(t_mlx *m)
{
	int		i;
	int		j;

	i = 0;
	m->a = -1;
	while (m->tab[i] && m->a == -1)
	{
		j = 0;
		while (m->tab[i][j] && m->a == -1)
		{
			if (m->tab[i][j] == 'P')
			{
				m->a = i;
				m->b = j;
			}
			j++;
		}
		i++;
	}
}

void	print_img_move(t_mlx *m)
{
	if (m->tab[m->a][m->b] == 'E')
	{
		m->img = mlx_xpm_file_to_image(m->mlx, DOOR, &m->x, &m->y);
		mlx_put_image_to_window(m->mlx, m->win, m->img, m->b * 32, m->a * 32);
	}
	else
	{
		m->img = mlx_xpm_file_to_image(m->mlx, TERRAIN, &m->x, &m->y);
		mlx_put_image_to_window(m->mlx, m->win, m->img, m->b * 32, m->a * 32);
	}
}

void	move_back_or_front(t_mlx *m)
{
	if ((m->key == S && m->tab[m->a + 1][m->b] != '1')
		|| (m->key == W && m->tab[m->a - 1][m->b] != '1'))
	{
		print_img_move(m);
		if (m->key == S)
			m->a += 1;
		else
			m->a -= 1;
		m->img = mlx_xpm_file_to_image(m->mlx, FIRE, &m->x, &m->y);
		mlx_put_image_to_window(m->mlx, m->win, m->img, m->b * 32, m->a * 32);
	}
	if (m->tab[m->a][m->b] == 'C')
		m->tab[m->a][m->b] = '0';
	if (m->tab[m->a][m->b] == 'E' && check_tab(m) == 0)
		exit(0);
}

void	move_right_or_left(t_mlx *m)
{
	if ((m->key == D && m->tab[m->a][m->b + 1] != '1')
		|| (m->key == A && m->tab[m->a][m->b - 1] != '1'))
	{
		print_img_move(m);
		if (m->key == D)
			m->b += 1;
		else
			m->b -= 1;
		m->img = mlx_xpm_file_to_image(m->mlx, FIRE, &m->x, &m->y);
		mlx_put_image_to_window(m->mlx, m->win, m->img, m->b * 32, m->a * 32);
	}
	if (m->tab[m->a][m->b] == 'C')
		m->tab[m->a][m->b] = '0';
	if (m->tab[m->a][m->b] == 'E' && check_tab(m) == 0)
		exit(0);
}

void	move_player(t_mlx *m)
{
	if (m->key == D || m->key == A)
		move_right_or_left(m);
	else if (m->key == S || m->key == W)
		move_back_or_front(m);
}
