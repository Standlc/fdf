/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handlers_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:04:29 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/15 11:04:32 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/format_handlers.h"
#include "../include/utils.h"
#include "../include/ft_printf.h"

int	handle_c(va_list pargs, char *p, int length)
{
	(void)p;
	length = 1;
	ft_putchar(va_arg(pargs, int));
	return (length);
}

int	handle_s(va_list pargs, char *p, int length)
{
	p = va_arg(pargs, char *);
	if (!p)
	{
		write(1, "(null)", 6);
		return (6);
	}
	length = ft_putstr(p);
	return (length);
}

int	handle_i(va_list pargs, char *p, int length)
{
	p = ft_itoa(va_arg(pargs, int));
	if (!p)
		return (MALLOC_ERROR);
	length = ft_putstr(p);
	free(p);
	return (length);
}

int	handle_d(va_list pargs, char *p, int length)
{
	p = ft_itoa(va_arg(pargs, int));
	if (!p)
		return (MALLOC_ERROR);
	length = ft_putstr(p);
	free(p);
	return (length);
}
