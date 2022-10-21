/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:09:45 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/21 19:19:43 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void  check_line(char *str, t_error *error)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] != '1')
            error->wall = 1;
        i++;
    }
}  
int check_wall(char **tab, t_error *error, t_map *s)
{
    int i;

    check_line(tab[0], error);
    check_line(tab[s->width], error);
    i = 1;
    while (i < s->width)
    {
        if (tab[i][0] != '1' || tab[i][s->height] != '1')
            error->wall = 1;
        i++;
    }
    return (1);
}