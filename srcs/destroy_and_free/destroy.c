/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:44:27 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/16 13:34:56 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	red_cross(t_data *d)
{
	ft_printf("Red cross\n");
	ft_exit(d);
	return (0);
}

void	free_map(t_data *d)
{
	int	i;

	i = d->s->width;
	while (--i >= 0)
		free(d->m->tab[i]);
	free(d->m->tab);
}

void	free_struct(t_data *d)
{
	free(d->s);
	free(d->error);
	free(d->w);
	free(d->m);
	free(d->t);
	free(d->p);
	free(d->e);
	free(d->f);
	free(d);
}

void	close_window(t_data *d)
{
	if (d->m->img)
		mlx_destroy_image(d->m->mlx, d->m->img);
	if (d->m->win)
		mlx_destroy_window(d->m->mlx, d->m->win);
	destroy_sprite(d);
	if (BONUS)
	{
		destroy_player(d);
		destroy_enemy(d);
		destroy_font(d);
	}
	mlx_destroy_display(d->m->mlx);
	free(d->m->mlx);
}

void	ft_exit(t_data *d)
{
	free_map(d);
	close_window(d);
	free_struct(d);
	exit(0);
}
