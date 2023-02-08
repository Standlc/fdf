/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:51:41 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/07 14:00:05 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (!src || !dest)
		return (NULL);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		while (i < (int)n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	// char	dest[] = "Hello test";
// 	// char	src[] = "TEST TEST TEST";

// 	int	src2[] = {4, 5, 6, 7};
// 	int	dest2[] = {0, 1, 2, 3};

// 	// memmove(dest2, src2, 20);
// 	ft_memmove(dest2, src2, 20);
// 	//memmove(dest2, src2, 6);
// 	// printf("%s\n", dest);
// 	for(int i = 0; i < 10; i++)
// 		printf("%d\n", dest2[i]);
// }