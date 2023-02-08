/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:29:22 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/07 17:31:55 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!little[0])
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (i + j < len && big[i + j] && little[j]
				&& big[i + j] == little[j])
				j++;
			if (!little[j])
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}

// int main()
// {
// 	char	big[] = "HELLO WORLD";
// 	char	small[] = "O";

// 	printf("%s\n", strnstr("lorem ipsum dolor sit amet", "dolor", 15));
// 	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
// }