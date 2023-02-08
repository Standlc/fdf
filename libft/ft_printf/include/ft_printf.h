/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:59:22 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/15 14:59:26 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEXA_BASE_LOWER	"0123456789abcdef"
# define HEXA_BASE_UPPER	"0123456789ABCDEF"
# define FORMATS			"cspdiuxX%%"
# define MALLOC_ERROR		-1

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "utils.h"
# include "format_handlers.h"
# include "../../libft.h"

int	ft_printf(const char *str, ...);

#endif
