/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:12:28 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/28 11:53:32 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(void)
{
	static int	i = 1;

	ft_printf("Nb of move : %d\n", i);
	i++;
}

static int	putstr_key(int key, t_mlx *m)
{
	m->key = key;
	if (key == 100 || key == 97 || key == 119 || key == 115)
	{
		print_move();
		move_player(m);
	}
	return (0);
}

void	set_map(t_mlx *m, char **tab, int x, int y)
{
	m->tab = tab;
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, (x * 32), (y * 32), "so_long");
	item_location(m, tab);
	player_place(m);
	mlx_key_hook(m->win, putstr_key, m);
	mlx_loop(m->mlx);
}

void	item_location(t_mlx *m, char **tab)
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
			show_map(m, tab[i][j]);
			m->a += 32;
			j++;
		}
		m->a = 0;
		m->b += 32;
		i++;
	}
}

void	show_map(t_mlx *m, char c)
{
	if (c == '1')
		m->img = mlx_xpm_file_to_image(m->mlx, WALL, &m->x, &m->y);
	else if (c == '0')
		m->img = mlx_xpm_file_to_image(m->mlx, TERRAIN, &m->x, &m->y);
	else if (c == 'P')
		m->img = mlx_xpm_file_to_image(m->mlx, FIRE, &m->x, &m->y);
	else if (c == 'C')
		m->img = mlx_xpm_file_to_image(m->mlx, BOMB, &m->x, &m->y);
	else
		m->img = mlx_xpm_file_to_image(m->mlx, DOOR, &m->x, &m->y);
	mlx_put_image_to_window(m->mlx, m->win, m->img, m->a, m->b);
}
