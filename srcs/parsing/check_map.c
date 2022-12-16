/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:50:56 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/16 13:32:12 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	nb_line_file(char *str)
{
	int		fd;
	char	c;
	int		len;

	len = 0;
	fd = open(str, O_RDONLY);
	if (read(fd, &c, 1) == 0)
		return (0);
	while (read(fd, &c, 1) > 0)
		if (c == '\n')
			len++;
	close (fd);
	return (len + 1);
}

void	read_map(t_data *d, char *av)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(av, O_RDONLY);
	if (nb_line_file(av) == 0)
		return ;
	d->m->tab = malloc (sizeof(char *) * (nb_line_file(av) + 1));
	if (!d->m->tab)
		return ;
	str = get_next_line(fd);
	if (!str)
		return ;
	while (str)
	{
		d->m->tab[i++] = str;
		d->s->width++;
		str = get_next_line(fd);
	}
	d->m->tab[i] = NULL;
	close (fd);
}

int	check_tab(t_data *d)
{
	int		i;
	int		j;
	int		bomb;

	i = 0;
	bomb = 0;
	while (d->m->tab[i])
	{
		j = 0;
		while (d->m->tab[i][j])
		{
			if (d->m->tab[i][j] == 'C')
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

int	check_shape(t_data *d)
{
	int	i;

	i = 0;
	d->s->height = ft_strlen(d->m->tab[0]);
	while (d->m->tab[i])
	{
		if (d->s->height != ft_strlen(d->m->tab[i]))
			d->error->shape = 1;
		i++;
	}
	if (i == d->s->height || i <= 2 || d->s->height <= 3)
		d->error->shape = 1;
	return (1);
}

void	check_map(t_data *d, char **av)
{
	char	*str;

	str = ft_substr(av[1], ft_strlen(av[1]) - 4, 4);
	if (ft_strncmp(str, ".ber", 4) != 0)
	{
		free(str);
		print_error("The file is not a .ber", d, 1);
	}
	free(str);
	read_map(d, av[1]);
	if (!d->m->tab)
		print_error("The file is empty", d, 1);
	check_shape(d);
	check_char(d);
	check_wall(d);
	find_error(d);
	check_way(d->m->tab, d);
	free_map(d);
	d->s->width = 0;
	read_map(d, av[1]);
}
