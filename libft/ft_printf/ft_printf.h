/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <stde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:59:22 by stde-la-          #+#    #+#             */
/*   Updated: 2023/02/07 12:33:33 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEXA_BASE_LOWER	"0123456789abcdef"
# define HEXA_BASE_UPPER	"0123456789ABCDEF"
# define FORMATS			"cspdiuxX%%"
# define MALLOC_ERROR		-1

# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft.h"

int		handle_c(va_list pargs, char *p, int length);
int		handle_s(va_list pargs, char *p, int length);
int		handle_i(va_list pargs, char *p, int length);
int		handle_d(va_list pargs, char *p, int length);
int		handle_u(va_list pargs, char *p, int length);
int		handle_x(va_list pargs, char *p, int length);
int		handle_upperx(va_list pargs, char *p, int length);
int		handle_percent(va_list pargs, char *p, int length);
int		handle_p(va_list pargs, char *p, int length);
char	*ft_unsigned_itoa(unsigned int n);
char	*ft_itohexa(unsigned long n, int is_lower_case);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_printf(const char *str, ...);

#endif
