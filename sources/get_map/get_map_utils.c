/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:33:27 by stde-la-          #+#    #+#             */
/*   Updated: 2023/02/01 12:33:28 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	rgb_to_hexa(t_rgb *rgb)
{
	return (rgb->red << 16 | rgb->green << 8 | rgb->blue);
}

int	get_rgb_component(char *str, int *index)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (i < 2 && (ft_isdigit(str[*index])
			|| (str[*index] >= 'A' && str[*index] <= 'F')))
	{
		nb = nb * 16 + ft_index_of(HEXA_BASE, str[*index]);
		(*index)++;
		i++;
	}
	return (nb);
}

void	get_rgb(char *file, t_map *point, int *index)
{
	int	i;
	int	hexa_len;

	i = *index;
	hexa_len = 0;
	while (ft_isdigit(file[i]) || (file[i] >= 'A' && file[i] <= 'F'))
	{
		i++;
		hexa_len++;
	}
	point->rgb.red = 0;
	point->rgb.green = 0;
	if (hexa_len == 6)
		point->rgb.red = get_rgb_component(file, index);
	if (hexa_len >= 3)
		point->rgb.green = get_rgb_component(file, index);
	point->rgb.blue = get_rgb_component(file, index);
}

void	assign_color_by_altitude(t_map *point)
{
	unsigned char	green;
	unsigned char	red;
	unsigned char	blue;

	if ((point->z * 10) + 127 > 255)
		green = 255;
	else if ((point->z * 10) + 127 < 0)
		green = 0;
	else
		green = (point->z * 10) + 127;
	if ((-point->z * 2.5) > 55)
		red = 55;
	else if ((-point->z * 2.5) < 0)
		red = 0;
	else
		red = (-point->z * 2.5);
	if (255 - red * 3 - green / 3 < 0)
		blue = 0;
	else
		blue = 255 - red * 3 - green / 3;
	point->rgb.red = red;
	point->rgb.green = green;
	point->rgb.blue = blue;
	point->hexa = rgb_to_hexa(&(point->rgb));
}

void	get_point_color(char *file, t_map *point, int *index)
{
	int	has_hexa_color;

	has_hexa_color = file[*index] == ',';
	if (has_hexa_color)
	{
		*index += 3;
		get_rgb(file, point, index);
		point->hexa = rgb_to_hexa(&(point->rgb));
	}
	else
		assign_color_by_altitude(point);
	skip_spaces(&file, index);
	if (file[*index] == '\n')
		(*index)++;
}
