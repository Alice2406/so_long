/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:45:03 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/14 18:23:30 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_error(t_data *d)
{
	if (d->error->char_map == 1)
		print_error("There is a character not allowed", d, 2);
	else if (d->error->shape == 1)
		print_error("The map is not rectangular", d, 2);
	else if (d->error->wall == 1)
		print_error("The map is not surrounded by wall", d, 2);
	else if (d->error->exit == 1)
		print_error("Nb of exit is incorrect", d, 2);
	else if (d->error->player == 1)
		print_error("Nb of player is incorrect", d, 2);
	else if (d->error->bomb == 1)
		print_error("Nb of collective is incorrect", d, 2);
	else if (d->error->way == 1)
		print_error("There is no way to solve the game", d, 2);
	else if (BONUS && d->error->enemy == 1)
		print_error("There are too many enemies on the map", d, 2);
	return (1);
}

int	print_error(char *msg, t_data *d, int c)
{
	if (c == 1)
		free_struct(d);
	if (c == 2)
	{
		free_map(d);
		free_struct(d);
	}
	ft_printf("Error : %s\n", msg);
	exit(0);
	return (0);
}
