/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bomb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:16:10 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/27 15:41:26 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_tab(t_mlx *m)
{
	int		i;
	int		j;
	int		bomb;

	i = 0;
	bomb = 0;
	while (m->tab[i])
	{
		j = 0;
		while (m->tab[i][j])
		{
			if (m->tab[i][j] == 'C')
				bomb++;
			j++;
		}
		i++;
	}
	if (bomb != 0)
		return (1);
	else
		return (0);
}
