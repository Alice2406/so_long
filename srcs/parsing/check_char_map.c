/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:46:30 by aniezgod          #+#    #+#             */
/*   Updated: 2022/12/09 14:56:03 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	ft_strchr2(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (s[i] == (char)c)
			return (c);
	}
	return (0);
}

void	count_char(t_data *d, char c)
{
	if (c == 'C')
		d->s->bomb++;
	else if (c == 'E')
		d->s->door++;
	else if (c == 'P')
		d->s->player++;
	else if (BONUS && c == 'N')
		d->m->enemy++;
}

void	check_nb_item(t_data *d)
{
	if (d->s->bomb < 1)
		d->error->bomb = 1;
	if (d->s->door != 1)
		d->error->exit = 1;
	if (d->s->player != 1)
		d->error->player = 1;
	if (BONUS && d->m->enemy > 1)
		d->error->enemy++;
}

int	check_char(t_data *d)
{
	char	*str;
	int		i;
	int		j;

	if (BONUS)
		str = "01CPEN\n";
	else
		str = "01CPE\n";
	i = 0;
	while (d->m->tab[i])
	{
		j = 0;
		while (d->m->tab[i][j])
		{
			if (ft_strchr2(str, d->m->tab[i][j]) == 0)
				d->error->char_map = 1;
			count_char(d, ft_strchr2(str, d->m->tab[i][j]));
			j++;
		}
		i++;
	}
	check_nb_item(d);
	return (1);
}
