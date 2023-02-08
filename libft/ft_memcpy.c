/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:15:47 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/07 11:51:26 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NOT READY

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*src_copy;
	char	*dest_copy;
	size_t	i;

	src_copy = (char *)src;
	dest_copy = (char *)dest;
	i = 0;
	while (i < n)
	{
		dest_copy[i] = src_copy[i];
		i++;
	}
	return (dest);
}

// void				*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	unsigned char	*new_dest;
// 	unsigned char	*new_src;
// 	size_t			i;

// 	if (!dest && !src)
// 		return (0);
// 	new_dest = dest;
// 	new_src = (unsigned char *)src;
// 	i = 0;
// 	while (i++ < n)
// 		*new_dest++ = *new_src++;
// 	return (dest);
// }

// int main()
// {
// 	char	arr[] = "HELLO WORLD";
// 	char	arr2[] = "D\0";

// 	char	*res = (char *)memcpy(arr, arr2, 2);
// 	// char	*res = (char *)ft_memcpy(arr, arr2, 5);

// 	for (int i = 0; i < 11; i++)
// 		printf("%c", ((char *)res)[i]);
// 	// for (int i = 0; i < 10; i++)
// 	// 	printf("%c\n", ((char *)ft_memset(arr2, -50, 10))[i]);
// }
