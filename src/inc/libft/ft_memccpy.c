/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:27:10 by cterrill          #+#    #+#             */
/*   Updated: 2017/04/22 22:35:56 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;
	unsigned int	i;

	i = 0;
	source = (unsigned char*)src;
	destination = (unsigned char*)dst;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
		if (source[i - 1] == (unsigned char)c)
			return ((void*)&dst[i]);
	}
	return (NULL);
}
