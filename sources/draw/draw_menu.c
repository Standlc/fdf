/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:43:44 by stde-la-          #+#    #+#             */
/*   Updated: 2023/02/03 15:43:47 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	draw_menu(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 15, 50, 0xFFFFFF, "Reset: 'R'");
	mlx_string_put(data->mlx, data->win, 15, 100, 0xFFFFFF, "Move: Arrows");
	mlx_string_put(data->mlx, data->win, 15, 150, 0xFFFFFF, "Zoom: '-' / '+'");
	mlx_string_put(data->mlx, data->win, 15, 200, 0xFFFFFF,
		"Toggle Perspective: 'P'");
	mlx_string_put(data->mlx, data->win, 15, 250, 0xFFFFFF,
		"Altitude sensibility: 'S' / 'W'");
	mlx_string_put(data->mlx, data->win, 15, 300, 0xFFFFFF, "Rotate:");
	mlx_string_put(data->mlx, data->win, 15, 325, 0xFFFFFF, "  z: '1' / '2'");
	mlx_string_put(data->mlx, data->win, 15, 350, 0xFFFFFF, "  y: '3' / '4'");
	mlx_string_put(data->mlx, data->win, 15, 375, 0xFFFFFF, "  x: '5' / '6'");
}
