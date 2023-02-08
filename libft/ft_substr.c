/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:40:23 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/08 15:43:31 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	size(char const *s, unsigned int start, size_t len)
{
	if (start > ft_strlen(s))
		return (1);
	if (ft_strlen(s) + 1 - start > len)
		return (len + 1);
	return (ft_strlen(s) + 1 - start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	res = malloc(size(s, start, len) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (start < ft_strlen(s) && i < len && s[i + start])
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = 0;
	return (res);
}

// int main()
// {
// 	printf("%s\n", ft_substr("tripouille", 1, 1));
// }