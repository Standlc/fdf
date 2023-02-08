/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:29:25 by stde-la-          #+#    #+#             */
/*   Updated: 2023/01/25 17:29:26 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_camera(t_data *data)
{
	data->camera.x_offset = 0;
	data->camera.y_offset = 0;
	data->camera.x_rotate = 0;
	data->camera.y_rotate = 0;
	data->camera.z_rotate = 0;
	data->camera.altitude_sensibility = 1;
	data->camera.iso_projection = 1;
	data->camera.zoom = 10;
}

void	init_data(t_data *data)
{
	data->map_height = 0;
	data->map_width = 0;
	init_camera(data);
}

int	main(int argc, char **argv)
{
	t_data			data;

	if (argc != 2)
		return (1);
	init_data(&data);
	ft_printf("🗺️  Reading map ");
	data.map = get_map(argv[1], &data);
	if (!data.map)
		return (write(2, "Map error\n", 10), 1);
	ft_printf("🚀 Starting mlx\n");
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fdf");
	data.img.p = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.img_addr = mlx_get_data_addr(data.img.p, &data.img.bpp,
			&data.img.line_length, &data.img.endian);
	display_map(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.p, 0, 0);
	draw_menu(&data);
	mlx_hook(data.win, 2, 1L << 0, handle_key, &data);
	mlx_hook(data.win, ON_DESTROY, ON_DESTROY, close_program, &data);
	mlx_loop(data.mlx);
	return (0);
}
