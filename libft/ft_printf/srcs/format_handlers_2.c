/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handlers_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <stde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:07:38 by stde-la-          #+#    #+#             */
/*   Updated: 2023/02/07 12:32:44 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_u(va_list pargs, char *p, int length)
{
	p = ft_unsigned_itoa(va_arg(pargs, unsigned int));
	if (!p)
		return (MALLOC_ERROR);
	length = ft_putstr(p);
	free(p);
	return (length);
}

int	handle_x(va_list pargs, char *p, int length)
{
	p = ft_itohexa((unsigned int)va_arg(pargs, int), 1);
	if (!p)
		return (MALLOC_ERROR);
	length = ft_putstr(p);
	free(p);
	return (length);
}

int	handle_upperx(va_list pargs, char *p, int length)
{
	p = ft_itohexa((unsigned int)va_arg(pargs, int), 0);
	if (!p)
		return (MALLOC_ERROR);
	length = ft_putstr(p);
	free(p);
	return (length);
}

int	handle_percent(va_list pargs, char *p, int length)
{
	(void)pargs;
	(void)p;
	length = 1;
	ft_putchar('%');
	return (length);
}

int	handle_p(va_list pargs, char *p, int length)
{
	p = ft_itohexa(va_arg(pargs, long), 1);
	if (!p)
		return (MALLOC_ERROR);
	if (p && p[0] == '0')
	{
		write(1, "(nil)", 5);
		free(p);
		return (5);
	}
	write(1, "0x", 2);
	length = ft_putstr(p) + 2;
	free(p);
	return (length);
}
