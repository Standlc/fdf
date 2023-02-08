/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:14:13 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/15 11:14:14 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

char			*ft_unsigned_itoa(unsigned int n);
char			*ft_itohexa(unsigned long n, int is_lower_case);
int				ft_putstr(char *s);
int				ft_putchar(char c);
unsigned int	absolute(int n);

#endif
