/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:02:25 by stde-la-          #+#    #+#             */
/*   Updated: 2023/02/01 12:02:27 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static double	get_currpoint_advancement(t_point *curr, t_point *a, t_point *b)
{
	if (a->x != b->x)
	{
		if (a->x < b->x)
			return ((curr->x - a->x) / abs_double(a->x - b->x));
		else
			return (1 - (curr->x - b->x) / abs_double(a->x - b->x));
	}
	if (a->y < b->y)
		return ((curr->y - a->y) / abs_double(a->y - b->y));
	else
		return (1 - (curr->y - b->y) / abs_double(a->y - b->y));
}

static char	get_curr_rgb_comp(unsigned char start_rgb_comp,
	unsigned char end_rgb_comp, double ratio)
{
	if (start_rgb_comp <= end_rgb_comp)
		return ((ratio * (end_rgb_comp - start_rgb_comp)) + start_rgb_comp);
	return (((1 - ratio) * (start_rgb_comp - end_rgb_comp)) + end_rgb_comp);
}

int	pixel_color(t_point *curr, t_point *a, t_point *b)
{
	double	ratio;

	if (abs(a->hexa - b->hexa) <= 50)
		return (a->hexa);
	ratio = get_currpoint_advancement(curr, a, b);
	curr->rgb.red = get_curr_rgb_comp(a->rgb.red, b->rgb.red, ratio);
	curr->rgb.green = get_curr_rgb_comp(a->rgb.green, b->rgb.green, ratio);
	curr->rgb.blue = get_curr_rgb_comp(a->rgb.blue, b->rgb.blue, ratio);
	return (rgb_to_hexa(&(curr->rgb)));
}
