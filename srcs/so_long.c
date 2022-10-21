/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:14:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/21 12:30:21 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map s;
	
	if (ac != 2)
	{
		ft_printf("Error : nb of arguments\n");
        return (0);
	}
	if(check_map(&s, av) == 1)
		ft_printf("coool\n");
}
