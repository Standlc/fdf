/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <stde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:47:49 by stde-la-          #+#    #+#             */
/*   Updated: 2023/02/07 13:13:45 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		write(1, s + i, 1);
		i++;
	}
	return (ft_strlen(s));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
