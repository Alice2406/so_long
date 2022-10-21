/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   note.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniezgod <aniezgod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:15:41 by aniezgod          #+#    #+#             */
/*   Updated: 2022/10/20 14:16:10 by aniezgod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// t_data data;

// static int putstr_key (int key)
// {
// 	ft_printf("%d\n", key);
// 	return 0;
// }

// int	main(void)
// {
// 	void	*mlx = mlx_init();
// 	void	*win = mlx_new_window(mlx, 500, 500, "hello world");

// 	ft_memset(&data, 0, sizeof(t_data));
	
// 	data.img = mlx_xpm_file_to_image(mlx, "MR_doodle.xpm", &data.x, &data.y);
// 	data.addr = mlx_get_data_addr(mlx, &data.bits_per_pixel, &data.line_length, &data.endian);

// 	mlx_put_image_to_window(mlx, win, data.img, 50, 50);

// 	mlx_key_hook(win, putstr_key, NULL);

// 	mlx_loop(mlx);
	
// }

/*


mlx_init (init la mlx) ! attention debut des leaks 


mlx_new_window
mlx_destroy_window

(mlx_new_image)


mlx_xpm_file_to_image

mlx_get_data_addr

mlx_put_image_to_window

mlx_destroy_image

mlx_key_hook

mlx_loop_hook

mlx_loop


(mlx_string_put)
*/
