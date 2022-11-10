/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:44:27 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/10 12:48:21 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_destroy(t_mlx *m)
{
	int	y;

	y = 0;
	while (m->tab[y])
	{
		free(m->tab[y]);
		y++;
	}
}

int destroy_window(t_mlx *m)
{
	mlx_destroy_window(m->mlx, m->win);
	map_destroy(m);
	exit (0);
}
