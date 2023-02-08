/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:33:15 by stde-la-          #+#    #+#             */
/*   Updated: 2023/02/01 12:33:17 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	check_hexa_color(char **map_line)
{
	int	hexa_color_len;

	if (**map_line == ',')
	{
		hexa_color_len = 0;
		if (*(*map_line + 1) == '0' && *(*map_line + 2) == 'X')
			*map_line += 3;
		else
			return (-1);
		while (ft_isdigit(**map_line)
			|| (**map_line >= 'A' && **map_line <= 'F'))
		{
			hexa_color_len++;
			(*map_line)++;
		}
		if (hexa_color_len > 6 || !hexa_color_len)
			return (-1);
	}
	return (0);
}

void	skip_spaces(char **map_line, int *index)
{
	if (index)
	{
		while ((*map_line)[*index] == ' ')
			(*index)++;
	}
	else
	{
		while (**map_line == ' ')
			(*map_line)++;
	}
}

int	get_map_width(char *map_line)
{
	int	count;

	ft_str_toupper(map_line);
	count = 0;
	while (*map_line && *map_line != '\n')
	{
		skip_spaces(&map_line, NULL);
		if (*map_line == '-')
		{
			map_line++;
			if (!ft_isdigit(*map_line))
				return (-1);
		}
		while (ft_isdigit(*map_line))
			map_line++;
		if (check_hexa_color(&map_line) == -1)
			return (-1);
		skip_spaces(&map_line, NULL);
		if (!ft_isdigit(*map_line)
			&& *map_line && *map_line != '-' && *map_line != '\n')
			return (-1);
		count++;
	}
	return (count);
}
