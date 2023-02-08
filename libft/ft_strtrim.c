/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:45:54 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/08 15:46:22 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc ft_strtrim.c ft_strchr.c ft_strlen.c ft_strdup.c ft_strlcpy.c

#include "libft.h"

// int	ft_getstart(const char *s1, const char *set)
// {
// 	size_t	len;
// 	size_t	i;

// 	len = ft_strlen(s1);
// 	i = 0;
// 	while (i < len)
// 	{
// 		if (ft_strchr(set, s1[i]) == 0)
// 			break ;
// 		i++;
// 	}
// 	return (i);
// }

// int	ft_getend(const char *s1, const char *set)
// {
// 	size_t	len;
// 	size_t	i;

// 	len = ft_strlen(s1);
// 	i = 0;
// 	while (i < len)
// 	{
// 		if (ft_strchr(set, s1[len - i - 1]) == 0)
// 			break ;
// 		i++;
// 	}
// 	return (len - i);
// }

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	int		start;
// 	int		end;
// 	char	*newstr;

// 	if (s1 == NULL)
// 		return (NULL);
// 	if (set == NULL)
// 		return (ft_strdup(s1));
// 	start = ft_getstart(s1, set);
// 	end = ft_getend(s1, set);
// 	if (start >= end)
// 		return (ft_strdup(""));
// 	newstr = (char *)malloc(sizeof(char) * (end - start + 1));
// 	if (newstr == NULL)
// 		return (NULL);
// 	ft_strlcpy(newstr, s1 + start, end - start + 1);
// 	return (newstr);
// }

int	check_sep(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

void	trim(char const *s1, char *res, int *boundaries)
{
	int	i;

	i = 0;
	while (s1[boundaries[0]] && boundaries[0] < boundaries[1])
	{
		res[i] = s1[boundaries[0]];
		i++;
		boundaries[0]++;
	}
	res[i] = 0;
}

void	get_boundaries(char const *s1, char const *set, int *boundaries)
{
	int		j;

	boundaries[0] = 0;
	boundaries[1] = 0;
	while (s1[boundaries[1]])
	{
		j = 0;
		if (check_sep(s1[boundaries[1]], set))
		{
			while (s1[boundaries[1] + j]
				&& check_sep(s1[boundaries[1] + j], set))
				j++;
			if (!boundaries[1] && !s1[boundaries[1] + j])
				break ;
			if (!s1[boundaries[1] + j])
				break ;
		}
		if (!boundaries[1])
			boundaries[0] = boundaries[1] + j;
		boundaries[1]++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		boundaries[2];

	get_boundaries(s1, set, boundaries);
	res = malloc(boundaries[1] - boundaries[0] + 1);
	if (!res)
		return (0);
	trim(s1, res, boundaries);
	return (res);
}

// int main()
// {
// 	printf("%s", ft_strtrim("   xxxtripouille", " x"));
//     return 0;
// }