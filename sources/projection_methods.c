/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_methods.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:02:15 by stde-la-          #+#    #+#             */
/*   Updated: 2023/02/01 12:02:18 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

double	project_x(t_camera *camera, t_map *point)
{
	if (camera->iso_projection)
		return ((point->x - point->y) * cos(RAD_ANGLE));
	return (point->x);
}

double	project_y(t_camera *camera, t_map *point)
{
	if (camera->iso_projection)
		return ((point->x + point->y) * sin(RAD_ANGLE) - point->z);
	return (point->y);
}

void	rotate_z_axis(double rotation, t_map *point)
{
	double	x;

	if (!rotation)
		return ;
	x = point->x;
	point->x = x * cos(rotation) - point->y * sin(rotation);
	point->y = x * sin(rotation) + point->y * cos(rotation);
}

void	rotate_x_axis(double rotation, t_map *point)
{
	double	y;

	if (!rotation)
		return ;
	y = point->y;
	point->y = y * cos(rotation) + point->z * sin(rotation);
	point->z = -y * sin(rotation) + point->z * cos(rotation);
}

void	rotate_y_axis(double rotation, t_map *point)
{
	double	x;

	if (!rotation)
		return ;
	x = point->x;
	point->x = x * cos(rotation) + point->z * sin(rotation);
	point->z = -x * sin(rotation) + point->z * cos(rotation);
}
