/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:32:04 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/07 17:42:00 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// INCREASES INDEX FROM GET_MAP()

long int	ft_atoi(const char *nptr, int *ind)
{
	long int	nb;
	int			sign;

	nb = 0;
	sign = 1;
	while ((nptr[(*ind)] >= 9 && nptr[(*ind)] <= 13) || nptr[(*ind)] == ' ')
		(*ind)++;
	if (nptr[(*ind)] == '+' || nptr[(*ind)] == '-')
	{
		if (nptr[(*ind)] == '-')
			sign = -1;
		(*ind)++;
	}
	while (nptr[(*ind)] && nptr[(*ind)] >= '0' && nptr[(*ind)] <= '9')
	{
		nb = nb * 10 + nptr[(*ind)] - '0';
		(*ind)++;
	}
	return (nb * sign);
}
