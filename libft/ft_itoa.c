/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <stde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:47:34 by stde-la-          #+#    #+#             */
/*   Updated: 2023/02/07 12:27:48 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*ascii;
	int				i;
	unsigned int	unsigned_n;

	unsigned_n = ft_abs(n);
	ascii = malloc(len(n) + 1);
	if (!ascii)
		return (0);
	i = len(n) - 1;
	ascii[i + 1] = 0;
	ascii[0] = '0';
	if (n < 0)
		ascii[0] = '-';
	while (unsigned_n)
	{
		ascii[i] = unsigned_n % 10 + '0';
		unsigned_n /= 10;
		i--;
	}
	return (ascii);
}

// int main()
// {
// 	printf("%s", ft_itoa(0));
// }