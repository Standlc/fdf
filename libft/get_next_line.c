/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:47:17 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/15 16:23:58 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*handle_read_error(char **buf)
{
	free(*buf);
	*buf = NULL;
	return (NULL);
}

static char	*ft_realloc(char *arr, int new_size)
{
	char	*temp;

	temp = malloc(ft_stringlen(arr, '\0') + 1);
	if (!temp)
		return (NULL);
	ft_strcpy(temp, arr);
	free(arr);
	arr = malloc(new_size);
	if (arr)
		ft_strcpy(arr, temp);
	free(temp);
	return (arr);
}

static char	*read_line(char *buf, int fd)
{
	int		read_bytes;
	int		offset;

	if (!buf)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		buf[0] = '\0';
	}
	offset = ft_stringlen(buf, '\0');
	read_bytes = BUFFER_SIZE;
	while (!is_line_read(buf) && read_bytes == BUFFER_SIZE && buf)
	{
		read_bytes = read(fd, buf + offset, BUFFER_SIZE);
		if (read_bytes == -1)
			return (handle_read_error(&buf));
		buf[offset + read_bytes] = '\0';
		offset += read_bytes;
		buf = ft_realloc(buf, offset + BUFFER_SIZE + 1);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = read_line(buf, fd);
	if (!buf)
		return (NULL);
	line = get_clean_line(buf);
	if (!line)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	get_excess(buf);
	return (line);
}

// # include <stdio.h>
// # include <fcntl.h>
// # include <unistd.h>
// int main()
// {
// 	int	fd = open("get_next_line.c", O_RDONLY);
// 	char 	*line;

// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		// printf("//////////////////////////////\n");
// 		free(line);
// 		line = get_next_line(fd);
// 	}

// 	close(fd);
// 	return (0);
// }
