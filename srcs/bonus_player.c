/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:55:08 by aniezgod          #+#    #+#             */
/*   Updated: 2022/11/07 18:21:17 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// t_bonus	init_bonus(void)
// {
// 	t_bonus	b;

// 	b.life = 0;
// 	return (b);
// }

void	move_back_or_front_bonus(t_mlx *m, char *stade)
{
	if ((m->key == S && m->tab[m->a + 1][m->b] != '1')
		|| (m->key == W && m->tab[m->a - 1][m->b] != '1'))
	{
		print_img_move(m);
		if (m->key == S)
		{
			m->a += 1;
			m->img = mlx_xpm_file_to_image(m->mlx, stade, &m->x, &m->y);
		}
		else
		{
			m->a -= 1;
			m->img = mlx_xpm_file_to_image(m->mlx, stade, &m->x, &m->y);
		}
		mlx_put_image_to_window(m->mlx, m->win, m->img, m->b * 32, m->a * 32);
	}
	if (m->tab[m->a][m->b] == 'C')
		m->tab[m->a][m->b] = '0';
	if (m->tab[m->a][m->b] == 'E' && check_tab(m) == 0)
		exit(0);
}

void	move_right_or_left_bonus(t_mlx *m, char *stade)
{
	if ((m->key == D && m->tab[m->a][m->b + 1] != '1')
		|| (m->key == A && m->tab[m->a][m->b - 1] != '1'))
	{
		print_img_move(m);
		if (m->key == D)
		{
			m->b += 1;
			m->img = mlx_xpm_file_to_image(m->mlx, stade, &m->x, &m->y);
		}
		else
		{
			m->b -= 1;
			m->img = mlx_xpm_file_to_image(m->mlx, stade, &m->x, &m->y);
		}
		mlx_put_image_to_window(m->mlx, m->win, m->img, m->b * 32, m->a * 32);
	}
	if (m->tab[m->a][m->b] == 'C')
		m->tab[m->a][m->b] = '0';
	if (m->tab[m->a][m->b] == 'E' && check_tab(m) == 0)
		exit(0);
}

int	check_life(int life, t_mlx *m)
{
	if (life < 2 && m->key == D && m->tab[m->a][m->b + 1] == 'C')
		life++;
	else if (life < 2 && m->key == A && m->tab[m->a][m->b - 1] == 'C')
		life++;
	else if (life < 2 && m->key == S && m->tab[m->a + 1][m->b] == 'C')
		life++;
	else if (life < 2 && m->key == W && m->tab[m->a - 1][m->b] == 'C')
		life++;
	return (life);
}

void	move_player_bonus(t_mlx *m)
{
	char *stade;
	static int life = 0;

	life = check_life(life, m);
	ft_printf("%d\n", life);
	if (life == 0)
		stade = "./textures/enemies1.xpm";
	else if (life == 1)
		stade = "./textures/enemies2.xpm";
	else if (life == 2)
		stade = "./textures/test.xpm";
	ft_printf("%s\n", stade);
	if (m->key == D || m->key == A)
		move_right_or_left_bonus(m, stade);
	else if (m->key == S || m->key == W)
		move_back_or_front_bonus(m, stade);
}