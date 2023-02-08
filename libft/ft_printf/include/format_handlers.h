/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handlers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:08:27 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/15 11:08:29 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_HANDLERS_H
# define FORMAT_HANDLERS_H

# include "./utils.h"

int	handle_c(va_list pargs, char *p, int length);
int	handle_s(va_list pargs, char *p, int length);
int	handle_i(va_list pargs, char *p, int length);
int	handle_d(va_list pargs, char *p, int length);
int	handle_u(va_list pargs, char *p, int length);
int	handle_x(va_list pargs, char *p, int length);
int	handle_upperx(va_list pargs, char *p, int length);
int	handle_percent(va_list pargs, char *p, int length);
int	handle_p(va_list pargs, char *p, int length);

#endif