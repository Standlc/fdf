/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:05:14 by stde-la-          #+#    #+#             */
/*   Updated: 2023/01/30 21:05:16 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	translate(int key, t_camera *camera)
{
	if (key == UP)
		camera->y_offset += 10 / camera->zoom;
	else if (key == DOWN)
		camera->y_offset -= 10 / camera->zoom;
	else if (key == LEFT)
		camera->x_offset += 10 / camera->zoom;
	else if (key == RIGHT)
		camera->x_offset -= 10 / camera->zoom;
}

void	zoom(int key, double *zoom)
{
	if (key == ZOOM_IN && *zoom < 1000)
		*zoom *= 1.1;
	else if (key == ZOOM_OUT)
		*zoom *= (double)10 / 11;
}

void	adjust_altitude(int key, double *altitude_sensibility)
{
	if (key == INCREASE_ALTITUDE && *altitude_sensibility < 5)
	{
		*altitude_sensibility *= 1.1;
		if (*altitude_sensibility == 0)
				*altitude_sensibility = 0.1;
	}
	else if (key == DECREASE_ALTITUDE)
	{
		if (*altitude_sensibility <= 0.1)
			*altitude_sensibility = 0;
		else
			*altitude_sensibility *= (double)10 / 11;
	}
}

void	change_rotation(double *rotation_axis, int condition)
{
	if (condition)
		*rotation_axis -= M_PI / 100;
	else
		*rotation_axis += M_PI / 100;
}

void	rotate(int key, t_camera *camera)
{
	if (key == ROTATE_Z_LEFT || key == ROTATE_Z_RIGHT)
		change_rotation(&(camera->z_rotate), key == ROTATE_Z_LEFT);
	else if (key == ROTATE_X_LEFT || key == ROTATE_X_RIGHT)
		change_rotation(&(camera->x_rotate), key == ROTATE_X_RIGHT);
	else if (key == ROTATE_Y_LEFT || key == ROTATE_Y_RIGHT)
		change_rotation(&(camera->y_rotate), key == ROTATE_Y_RIGHT);
}
