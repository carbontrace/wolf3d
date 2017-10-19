/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 22:00:49 by cterrill          #+#    #+#             */
/*   Updated: 2017/05/06 06:48:02 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	lil_size;

	if (*little == '\0')
		return ((char *)big);
	lil_size = ft_strlen(little);
	while (*big != '\0' && n-- >= lil_size)
	{
		if (*big == *little && ft_memcmp(big, little, lil_size) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
