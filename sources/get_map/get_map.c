/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:05:08 by stde-la-          #+#    #+#             */
/*   Updated: 2023/01/30 21:05:09 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static void	err_msg(char *message, char *p, int condition)
{
	if (!condition)
		return ;
	ft_printf("%s", message);
	if (p)
		free(p);
	exit(1);
}

static int	retrieve_coordinates(char *file, t_data *data, int x, int y)
{
	static int	index = 0;

	data->map[y][x].x = x - ((double)(data->map_width - 1) / 2);
	data->map[y][x].y = y - ((double)(data->map_height - 1) / 2);
	data->map[y][x].z = ft_atoi(file, &index) * 0.05;
	if (data->map[y][x].z > 1000.0 || data->map[y][x].z < -1000.0)
		return (1);
	get_point_color(file, &(data->map[y][x]), &index);
	return (0);
}

static t_map	**parse_map(char *file, t_data *data)
{
	int		i;
	int		j;

	ft_printf("\n🚧 Creating map\n");
	ft_str_toupper(file);
	data->map = malloc(sizeof(t_map *) * data->map_height);
	if (!data->map)
		return (free(file), NULL);
	i = -1;
	while (++i < data->map_height)
	{
		data->map[i] = malloc(sizeof(t_map) * data->map_width);
		if (!data->map[i])
			return (free(file), free_map(data, i + 1), NULL);
		j = -1;
		while (++j < data->map_width)
			if (retrieve_coordinates(file, data, j, i))
				return (free(file), free_map(data, i + 1), NULL);
	}
	return (free(file), data->map);
}

t_map	**get_map(char *file_path, t_data *data)
{
	int		fd;
	int		width;
	int		is_map_ok;
	char	*line;
	char	*file;

	is_map_ok = 1;
	file = NULL;
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	err_msg("\nMap error\n", NULL, !line);
	data->map_width = get_map_width(line);
	while (line)
	{
		width = get_map_width(line);
		is_map_ok = (is_map_ok && width != -1 && data->map_width == width);
		loader();
		file = ft_strjoin(file, line);
		if (!file)
			return (free(line), NULL);
		free(line);
		line = get_next_line(fd);
		(data->map_height)++;
	}
	return (err_msg("\nMap error\n", file, !is_map_ok), parse_map(file, data));
}
