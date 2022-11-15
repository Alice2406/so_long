/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:09:45 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/15 16:42:31 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_line(char *str, t_data *d)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			d->error->wall = 1;
		i++;
	}
}

int	check_wall(t_data *d)
{
	int	i;

	check_line(d->m->tab[0], d);
	check_line(d->m->tab[d->s->width - 1], d);
	i = 1;
	while (i < d->s->width)
	{
		if (d->m->tab[i][0] != '1' || d->m->tab[i][d->s->height - 1] != '1')
			d->error->wall = 1;
		i++;
	}
	return (1);
}
