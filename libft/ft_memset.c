/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:10:06 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/09 09:00:56 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

// int main()
// {
// 	char	arr[] = "HELLO WORLD";
// 	char	arr2[] = "HELLO WORLD";

// 	for (int i = 0; i < 10; i++)
// 		printf("%d\n", ((char *)memset(arr, -50, 10))[i]);
// 	for (int i = 0; i < 10; i++)
// 		printf("%d\n", ((char *)ft_memset(arr2, -50, 10))[i]);
// }
