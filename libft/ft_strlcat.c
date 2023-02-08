/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:08:55 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/08 15:37:07 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_index;
	size_t	dst_len;
	size_t	i;

	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	dst_len = ft_strlen(dst);
	dst_index = dst_len;
	i = 0;
	while (src[i] && i < size - dst_len - 1)
	{
		dst[dst_index + i] = src[i];
		i++;
	}
	dst[dst_index + i] = 0;
	return (ft_strlen(dst) + ft_strlen(src + i));
}

// int main()
// {
// 	char dest[30];
// 	memset(dest, 'C', 5);
// 	char * src = (char *)"AAAAAAAAA";
// 	printf("%ld\n", ft_strlcat(dest, src, -1));
// 	printf("%s", dest);
// }
