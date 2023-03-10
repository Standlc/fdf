/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <stde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:45:50 by stde-la-          #+#    #+#             */
/*   Updated: 2023/02/09 12:56:20 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	handle_key(int key, t_data *data)
{
	// printf("%d\n", key);
	if (key == ESC)
		close_program(data);
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		translate(key, &(data->camera));
	else if (key == ZOOM_IN || key == ZOOM_OUT)
		zoom(key, &(data->camera.zoom));
	else if (key == INCREASE_ALTITUDE || key == DECREASE_ALTITUDE)
		adjust_altitude(key, &(data->camera.altitude_sensibility));
	else if (key >= ROTATE_Z_LEFT && key <= ROTATE_Y_RIGHT)
		rotate(key, &(data->camera));
	else if (key == RESET)
		init_camera(data);
	else if (key == PERSPECTIVE_TOGGLE)
		data->camera.iso_projection = !data->camera.iso_projection;
	else if (key == HIDE_CONTROLS)
		data->show_controls = !data->show_controls;
	display_map(data);
	return (0);
}
