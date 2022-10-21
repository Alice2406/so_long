/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:50:56 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/21 19:18:11 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map   init_struct(void)
{
    t_map s;

    s.height = 0;
    s.width = 0;
    s.player = 0;
    s.door = 0;
    s.bomb = 0;
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
        s->width++;
        if (str)
           str2 = ft_strjoin(str2, str);
    }
    tab = ft_split(str2, '\n');
    close (fd);
    return (tab);
}

int check_shape(t_map *s, char **tab, t_error *error)
{
    int i;

    i = 0;
    s->height = ft_strlen(tab[0]);
    while (tab[i])
    {
        if (s->height != ft_strlen(tab[i]))
            error->shape = 1;
        i++;
    }
    if (i == s->height || i <= 2 || s->height <= 2)
        error->shape = 1;
    return (1);
}

int check_map(t_map *s, char **av, t_error *error)
{
    int fd;
    char *str;
    char **tab;

    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        print_error("The file doesn't exist", NULL);
    close (fd);
    str = ft_substr(av[1], ft_strlen(av[1]) - 4, 4);
    if (ft_strncmp(str, ".ber", 4) != 0)
        print_error("The file is not a .ber", NULL);
    *error = init_error();
    *s = init_struct();
    tab = read_map(s, av[1]);
    check_shape (s, tab, error);
    check_char(s, tab, error);
    check_wall(tab, error, s);
    return (1);
}