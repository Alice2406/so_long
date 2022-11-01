/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:03:27 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/01 18:14:39 by aniezgod         ###   ########.fr       */
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

void	flood_fill2(t_way *w, int a, int b)
{
	if (a < 1)
		flood_fill(w->map[w->x + 1][w->y], w, w->x + 1, w->y);
	if (b < 1)
		flood_fill(w->map[w->x][w->y + 1], w, w->x, w->y + 1);
	if (a > 5)
		flood_fill(w->map[w->x - 1][w->y], w, w->x - 1, w->y);
	if (b > 33)
		flood_fill(w->map[w->x][w->y - 1], w, w->x, w->y - 1);
}

void	flood_fill(char c, t_way *w, int a, int b)
{
	if (c != '1')
	{
		if (c == 'C')
			w->bomb++;
		if (c == 'E')
			w->exit++;
		if (w->exit == 1 && w->bomb == w->tbomb)
			return ;
		w->map[a][b] = 'x';
		w->x = a;
		w->y = b;
		flood_fill2(w, a, b);
		flood_fill(w->map[w->x + 1][w->y], w, w->x + 1, w->y);
		flood_fill(w->map[w->x - 1][w->y], w, w->x - 1, w->y);
		flood_fill(w->map[w->x][w->y + 1], w, w->x, w->y + 1);
		flood_fill(w->map[w->x][w->y - 1], w, w->x, w->y - 1);
	}
	else
	{
		ft_printf("(%d, %d)\n", a, b);
		flood_fill2(w, a, b);
	}

}

void	read_way(t_way *w)
{
	int	i;

	i = 0;
	while(w->map[i])
	{
		ft_printf("%s\n", w->map[i]);
		i++;
	}
}

void	check_way(char **tab, t_way *w, t_error *error)
{
	*w = init_way();
	nb_bomb(tab, w);
	w->map = tab;
	fire_place(w);
	flood_fill(w->map[w->x][w->y], w, w->x, w->y);
	read_way(w);
}