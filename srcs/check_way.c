/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:03:27 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/03 12:51:59 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_way	init_way(void)
{
	t_way	way;

	way.map = NULL;
	way.exit = 0;
	way.bomb = 0;
	way.tbomb = 0;
	way.x = 0;
	way.y = 0;
	return (way);
}

void	nb_bomb(char **tab, t_way *way)
{
	int	i;
	int	j;
	
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C')
				way->tbomb++;
			j++;
		}
		i++;
	}
}

void	fire_place(t_way *m)
{
	int		i;
	int		j;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == 'P')
			{
				m->x = i;
				m->y = j;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_way *w, int x, int y)
{
	if (w->map[x][y] == '1' || w->map[x][y] == 'x')
		return ;
	if (w->map[x][y] == 'C')
		w->bomb++;
	if (w->map[x][y] == 'E')
		w->exit++;
	w->map[x][y] = 'x';
	flood_fill(w, x, y + 1);
	flood_fill(w, x - 1, y);
	flood_fill(w, x, y - 1);
	flood_fill(w, x + 1, y);
	return ;
}

void	check_way(char **tab, t_way *w, t_error *error)
{
	int	x;
	int y;

	*w = init_way();
	w->map = tab;
	nb_bomb(w->map, w);
	fire_place(w);
	x = w->x;
	y = w->y;
	flood_fill(w, x, y);
	if (w->exit != 1 || w->tbomb != w->bomb)
		error->way = 1;
	
}
