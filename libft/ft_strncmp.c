/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:49:03 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/07 17:19:35 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	while (*s1 && *s2 && *s1 == *s2 && counter < n)
	{
		s1++;
		s2++;
		counter++;
	}
	if (counter == n)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char	*str1 = "HELLO";
// 	char	*str2 = "HELlO";

// 	printf("%d\n%d\n", strncmp(str1, str2), ft_strcmp(str1, str2));
// }
