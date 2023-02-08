/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:04:51 by stde-la-          #+#    #+#             */
/*   Updated: 2023/01/30 21:04:53 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_map(t_data *data, int up_to)
{
	int	i;

	i = 0;
	while (i < up_to)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

int	close_program(t_data *data)
{
	ft_printf("🥹 Leaving already?\n");
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.p);
	// mlx_destroy_display(data->mlx);
	free_map(data, data->map_height);
	free(data->mlx);
	exit (0);
}
