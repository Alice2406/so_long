/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:44:27 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/15 16:51:23 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_destroy(t_data *d)
{
	int	y;

	y = 0;
	while (d->m->tab[y])
	{
		free(d->m->tab[y]);
		y++;
	}
}

int	destroy_window(t_data *d)
{
	mlx_destroy_window(d->m->mlx, d->m->win);
	map_destroy(d);
	exit (0);
}
