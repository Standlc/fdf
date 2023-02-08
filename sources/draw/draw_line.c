/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:29:36 by stde-la-          #+#    #+#             */
/*   Updated: 2023/01/25 17:29:37 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.img_addr
		+ (y * data->img.line_length + x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}

double	abs_double(double nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static double	get_x_increment(double slope, t_point *a, t_point *b)
{
	if (slope <= 1)
		return ((a->x <= b->x) - (a->x > b->x));
	return ((1 / slope) * (a->x <= b->x) - (1 / slope) * (a->x > b->x));
}

static double	get_y_increment(double slope, t_point *a, t_point *b)
{
	if (slope <= 1)
		return ((slope * (a->y <= b->y)) - (slope * (a->y > b->y)));
	return ((a->y <= b->y) - (a->y > b->y));
}

void	draw_line(t_data *data, t_point *a, t_point *b)
{
	double	slope;
	double	x_increment;
	double	y_increment;
	t_point	curr;

	slope = abs_double(a->y - b->y) / abs_double(a->x - b->x);
	x_increment = get_x_increment(slope, a, b);
	y_increment = get_y_increment(slope, a, b);
	curr = *a;
	while (((a->x <= b->x && round(curr.x) <= b->x)
			|| (a->x > b->x && round(curr.x) >= b->x))
		&& ((a->y <= b->y && round(curr.y) <= b->y)
			|| (a->y > b->y && round(curr.y) >= b->y)))
	{
		if (is_point_inside_screen(round(curr.x), round(curr.y)))
			put_pixel(data, round(curr.x), round(curr.y),
				pixel_color(&curr, a, b));
		curr.x += x_increment;
		curr.y += y_increment;
	}
	if (is_point_inside_screen(b->x, b->y))
		put_pixel(data, b->x, b->y, b->hexa);
}
