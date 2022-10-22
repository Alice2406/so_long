/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:14:15 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/22 17:46:38 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// t_data	init_data(void)
// {
// 	t_data	data;

// 	data.x = 0;
// 	data.y = 0;
// 	data.bits_per_pixel = 0;
// 	data.endian = 0;
// 	data.line_length = 0;
// 	return (data);
// }

int	main(int ac, char **av)
{
	t_map	s;
	t_error	error;
	t_data	data;

	if (ac != 2)
		print_error("Nb of arguments", NULL);
	if (check_map(&s, av, &error) == 1)
		ft_printf("coool\n");

	ft_memset(&data, 0, sizeof(t_data));
 	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 500, "so_long");

	
	data.img = mlx_xpm_file_to_image(data.mlx, "./textures/fire.xpm", &data.x, &data.y);
	data.addr = mlx_get_data_addr(data.mlx, &data.bits_per_pixel, &data.line_length, &data.endian);

	mlx_put_image_to_window(data.mlx, data.win, data.img, 50, 50); //segfault is here !! 

	mlx_loop(data.mlx);
}


//init mes struct avec ft_memset