/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <stde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:05:01 by stde-la-          #+#    #+#             */
/*   Updated: 2023/02/09 12:57:51 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	is_point_inside_screen(double x, double y)
{
	return (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT);
}

static int	is_line_outside(t_point *a, t_point *b)
{
	return ((a->x < 0 && b->x < 0) || (a->y < 0 && b->y < 0)
		|| (a->x >= WIDTH && b->x >= WIDTH)
		|| (a->y >= HEIGHT && b->y >= HEIGHT));
}

static void	addpoint_toline(t_camera camera, t_point *line_point, t_map point)
{
	point.z *= camera.altitude_sensibility;
	rotate_x_axis(camera.x_rotate, &point);
	rotate_y_axis(camera.y_rotate, &point);
	rotate_z_axis(camera.z_rotate, &point);
	line_point->x = round((project_x(&camera, &point)
				+ camera.x_offset) * camera.zoom + WIDTH / 2);
	line_point->y = round((project_y(&camera, &point)
				+ camera.y_offset) * camera.zoom + HEIGHT / 2);
	line_point->rgb = point.rgb;
	line_point->hexa = point.hexa;
}

void	display_map(t_data *data)
{
	t_line	line;
	int		i;
	int		j;

	ft_bzero(data->img.img_addr, HEIGHT * WIDTH * (data->img.bpp / 8));
	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			addpoint_toline(data->camera, &(line.start), data->map[i][j]);
			if (j < data->map_width - 1)
			{
				addpoint_toline(data->camera, &(line.end), data->map[i][j + 1]);
				if (!is_line_outside(&(line.start), &(line.end)))
					draw_line(data, &(line.start), &(line.end));
			}
			if (i == data->map_height - 1)
				continue ;
			addpoint_toline(data->camera, &(line.end), data->map[i + 1][j]);
			if (!is_line_outside(&(line.start), &(line.end)))
				draw_line(data, &(line.start), &(line.end));
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.p, 0, 0);
	draw_controls(data);
}
