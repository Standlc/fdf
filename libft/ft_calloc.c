/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:42:18 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/15 13:56:10 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tab;
	size_t			mem;

	if (nmemb == 0 || size == 0)
		return (ft_calloc(1, 1));
	mem = nmemb * size;
	if (mem / nmemb != size)
		return (0);
	tab = malloc(mem);
	if (!tab)
		return (0);
	ft_bzero(tab, mem);
	return (tab);
}
