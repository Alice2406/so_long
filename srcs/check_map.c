/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:50:56 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/07 15:18:30 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(t_data *d, char *av, char **tab)
{
	char	*str;
	char	*str2;
	int		fd;

	fd = open(av, O_RDONLY);
	str = get_next_line(fd);
	str2 = str;
	while (str)
	{
		str = get_next_line(fd);
		d->s->width++;
		if (str)
			str2 = ft_strjoin(str2, str);
	}
	tab = ft_split(str2, '\n');
	close (fd);
	return (free(str2), tab);
}

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

int	check_shape(t_data *d, char **tab)
{
	int	i;

	i = 0;
	d->s->height = ft_strlen(tab[0]);
	while (tab[i])
	{
		if (d->s->height != ft_strlen(tab[i]))
			d->error->shape = 1;
		i++;
	}
	if (i == d->s->height || i <= 2 || d->s->height <= 2)
		d->error->shape = 1;
	return (1);
}

char	**check_map(t_data *d, char **av)
{
	int		fd;
	char	*str;
	char	**tab;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		print_error("The file doesn't exist", NULL);
	close (fd);
	str = ft_substr(av[1], ft_strlen(av[1]) - 4, 4);
	if (ft_strncmp(str, ".ber", 4) != 0)
	{
		free(str);
		print_error("The file is not a .ber", NULL);
	}
	free(str);
	tab = read_map(d, av[1], tab);
	check_shape(d, tab);
	check_char(d, tab);
	check_wall(tab, d);
	find_error(d, tab);
	check_way(tab, d);
	d->s->width = 0;
	tab = read_map(d, av[1], tab);
	return (tab);
}
