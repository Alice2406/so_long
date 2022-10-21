/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:45:03 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/21 19:20:24 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error init_error(void)
{
    t_error error;
    
    error.exit = 0; //done
	error.player = 0; //done
	error.bomb = 0; //done
	error.char_map = 0; //done
	error.shape = 0; //done
	error.wall = 0; 

    return (error);
}

int find_error(t_error *error, char **tab)
{
    if (error->exit == 1)
        print_error("Nb of exit is incorrect", tab);
    if (error->player == 1)
        print_error("Nb of player is incorrect", tab);
    if (error->bomb == 1)
        print_error("Nb of collective is incorrect", tab);
    if (error->char_map == 1)
        print_error("There is a character not allowed", tab);
    if (error->shape == 1)
        print_error("The map is not rectangular", tab);
    if (error->wall == 1)
        print_error("The map is not surrounded by wall", tab);
    return (1);
}

int    print_error(char *msg, char **tab)
{
    if (tab)
        free(*tab);   
    ft_printf("Error : %s\n", msg);
    exit(0);
    return (0);
}