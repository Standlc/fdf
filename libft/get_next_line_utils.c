/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:26:44 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/21 11:26:48 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_stringlen(char const *c, char end)
{
	int	i;

	i = 0;
	while (c[i] && c[i] != end)
		i++;
	if (c[i] == end && end != '\0')
		return (i + 1);
	return (i);
}

int	is_line_read(char *line)
{
	while (*line)
	{
		if (*line == '\n')
			return (1);
		line++;
	}
	return (0);
}

void	get_excess(char *buf)
{
	int	i;
	int	j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	j = 0;
	while (buf[i + j])
	{
		buf[j] = buf[i + j];
		j++;
	}
	buf[j] = '\0';
}

char	*get_clean_line(char *buf)
{
	char	*line;
	int		i;

	if (!buf[0])
		return (NULL);
	line = malloc(ft_stringlen(buf, '\n') + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i])
	{
		line[i] = buf[i];
		i++;
		if (buf[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	return (line);
}
