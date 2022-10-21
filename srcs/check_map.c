/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:50:56 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/21 13:57:27 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map   init_struct(void)
{
    t_map s;

    s.height = 0;
    s.width = 0;
    s.player = 0;
    s.wall = 0;
    s.door = 0;
    s.bomb = 0;
    s.corridor = 0;
    return (s);
}

char   **read_map(t_map *s, char *av)
{
    char *str;
    char *str2;
    char **tab;
    int fd;
    
    fd = open(av, O_RDONLY);
    str = get_next_line(fd);    
    str2 = str;
    while (str)
    {
        str = get_next_line(fd);
        s->height++;
        if (str)
           str2 = ft_strjoin(str2, str);
    }
    tab = ft_split(str2, '\n');
    close (fd);
    return (tab);
}

int check_shape(char **tab)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen(tab[0]);
    while (tab[i])
    {
        if (len != ft_strlen(tab[i]))
            return (0);
        i++;
    }
    if (i == len || i <= 2 || len <= 2)
        return (0);
    return (1);
}

int check_map(t_map *s, char **av)
{
    int fd;
    char *str;
    char **tab;

    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        ft_printf("The file doesn't exist\n");
        return (0);
    }
    close (fd);
    str = ft_substr(av[1], ft_strlen(av[1]) - 4, 4);
    if (ft_strncmp(str, ".ber", 4) != 0)
    {
        ft_printf("Error : the file is not a .ber\n");
        return (0);
    }
    *s = init_struct();
    tab = read_map(s, av[1]);
    if (check_shape (tab) == 0)
    {
        ft_printf("Error : the map is not rectangular\n");
        return (0);
    }
    return (1);
}