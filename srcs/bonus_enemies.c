/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:32:37 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/12 14:16:27 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

 void	move_4(int x, int y, t_mlx *m, char **tab)
 {
 	int		i;
 	int		j;
 	void	*img;

 	while (tab[y][x + 1] != '1')
 	{
 		img = mlx_xpm_file_to_image(m->mlx, "./textures/terrain.xpm", &m->x, &m->y);
 		mlx_put_image_to_window(m->mlx, m->win, img, x * 32, y * 32);
 		tab[y][x] = '0';
 		tab[y][x -1] = 'N';
 		i = y * 32;
 		j = (x * 32) - 32;
 		img = mlx_xpm_file_to_image(m->mlx, "./textures/bonus/S2PA.xpm", &m->x, &m->y);
 		mlx_put_image_to_window(m->mlx, m->win, img, j * 32, i * 32);
 		x++;
 	}	
 }

 void	move_2(int x, int y, t_mlx *m, char **tab)
 {
 	int		i;
 	int		j;
 	void	*img;

 	if (x == m->a && y == m->b)
 		ft_printf("touch by the ennemies\n");
 	if (tab[y][x - 1] != '1')
 	{
 		img = mlx_xpm_file_to_image(m->mlx, "./textures/terrain.xpm", &m->x, &m->y);
 		mlx_put_image_to_window(m->mlx, m->win, img, x * 32, y * 32);
 		tab[y][x] = '0';
 		tab[y][x -1] = 'N';
 		i = y * 32;
 		j = (x * 32) - 32;
 		img = mlx_xpm_file_to_image(m->mlx, "./textures/bonus/S2PA.xpm", &m->x, &m->y);
 		mlx_put_image_to_window(m->mlx, m->win, img, j * 32, i * 32);
 	}
 	else if (tab[y][x + 1] == '0')
 		move_4(x, y, m, tab);
 }

void	move_anim(t_mlx *m, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 33)
		{
			if (tab[i][j] == 'N')
				move_2(j, i, m, tab);
			j++;
		}
		i++;
	}
}

char	**get_tab(char *av, char **tab)
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
		if (str)
			str2 = ft_strjoin(str2, str);
	}
	tab = ft_split(str2, '\n');
	close (fd);
	return (free(str2), tab);
}

int	anim(t_mlx *m)
{
	char **tab;
	
	tab = get_tab("maps/base_bonus.ber", tab);
	m->enemyspeed++;
	if (m->enemyspeed >= 3000)
	{
		move_anim(m, tab);
		m->enemyspeed = 0;
	}
	return (0);
}
