/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:14:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/22 15:57:05 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	s;
	t_error	error;
	t_data	data;
	void	*mlx;
	void	*win;

	if (ac != 2)
		print_error("Nb of arguments", NULL);
	if (check_map(&s, av, &error) == 1)
		ft_printf("coool\n");

 	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "so_long");

//	ft_memset(&data, 0, sizeof(t_data));
	
	data.img = mlx_xpm_file_to_image(mlx, "../textures/fire.xpm", &data.x, &data.y);
//	data.addr = mlx_get_data_addr(mlx, &data.bits_per_pixel, &data.line_length, &data.endian);

/*	mlx_put_image_to_window(mlx, win, data.img, 50, 50);*/

	mlx_loop(mlx);
}
