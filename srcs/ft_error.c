/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:45:03 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/07 15:20:50 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_error(t_data *d, char **tab)
{
	if (d->error->char_map == 1)
		print_error("There is a character not allowed", tab);
	else if (d->error->shape == 1)
		print_error("The map is not rectangular", tab);
	else if (d->error->wall == 1)
		print_error("The map is not surrounded by wall", tab);
	else if (d->error->exit == 1)
		print_error("Nb of exit is incorrect", tab);
	else if (d->error->player == 1)
		print_error("Nb of player is incorrect", tab);
	else if (d->error->bomb == 1)
		print_error("Nb of collective is incorrect", tab);
	else if (d->error->way == 1)
		print_error("There is no way to solve the game", tab);
	return (1);
}

int	print_error(char *msg, char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free (tab[i]);
			i++;
		}
	}
	ft_printf("Error : %s\n", msg);
	exit(0);
	return (0);
}
