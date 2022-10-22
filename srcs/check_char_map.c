/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:46:30 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/22 12:30:55 by aniezgod         ###   ########.fr       */
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

void	count_char(t_map *s, char c)
{
	if (c == 'C')
		s->bomb++;
	else if (c == 'E')
		s->door++;
	else if (c == 'P')
		s->player++;
}

void	check_nb_item(t_map *s, t_error *error)
{
	if (s->bomb < 1)
		error->bomb = 1;
	if (s->door != 1)
		error->exit = 1;
	if (s->player != 1)
		error->player = 1;
}

int	check_char(t_map *s, char **tab, t_error *error)
{
	char	*str;
	int		i;
	int		j;

	str = "01CPE";
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (ft_strchr2(str, tab[i][j]) == 0)
				error->char_map = 1;
			count_char(s, ft_strchr2(str, tab[i][j]));
			j++;
		}
		i++;
	}
	check_nb_item(s, error);
	return (1);
}
