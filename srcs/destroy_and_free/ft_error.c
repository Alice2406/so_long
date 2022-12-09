/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:45:03 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/09 14:59:05 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_error(t_data *d)
{
	if (d->error->char_map == 1)
		print_error("There is a character not allowed", d);
	else if (d->error->shape == 1)
		print_error("The map is not rectangular", d);
	else if (d->error->wall == 1)
		print_error("The map is not surrounded by wall", d);
	else if (d->error->exit == 1)
		print_error("Nb of exit is incorrect", d);
	else if (d->error->player == 1)
		print_error("Nb of player is incorrect", d);
	else if (d->error->bomb == 1)
		print_error("Nb of collective is incorrect", d);
	else if (d->error->way == 1)
		print_error("There is no way to solve the game", d);
	else if (BONUS && d->error->enemy == 1)
		print_error("There are too many enemies on the map", d);
	return (1);
}

int	print_error(char *msg, t_data *d)
{
	int	i;

	i = 0;
	if (d->m->tab)
	{
		while (d->m->tab[i])
		{
			free (d->m->tab[i]);
			i++;
		}
	}
	ft_printf("Error : %s\n", msg);
	exit(0);
	return (0);
}
