/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:46:41 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/08 15:47:21 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	item_len(char c, char const *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

void	copy(char *dest, char const **str, char c)
{
	while (**str && **str != c)
	{
		*dest = **str;
		dest++;
		(*str)++;
	}
	*dest = 0;
}

int	item_count(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c && item_len(c, str) > 0)
		{
			count++;
			while (*str && *str != c)
				str++;
			if (!*str)
				break ;
		}
		str++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	if (!s || (s && !(item_count(s, c))))
		return (0);
	arr = malloc((item_count(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c && item_len(c, s) > 0)
		{
			arr[i] = malloc((item_len(c, s) + 1) * sizeof(char));
			copy(arr[i], &s, c);
			i++;
			if (!*s)
				break ;
		}
		s++;
	}
	arr[i] = 0;
	return (arr);
}

// int main()
// {
// 	char	**arr = ft_split("lorem ipsum dolor
//  sndisse lectcie
// s sed, dolonas ligula massa, varius 
// a, semper congue, euismod non, mi.", 'i');
// 	for (int i = 0; arr[i]; i++)
// 		printf("%s\n", arr[i]);
// }
