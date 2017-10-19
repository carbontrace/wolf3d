/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:04:38 by cterrill          #+#    #+#             */
/*   Updated: 2017/04/23 14:58:50 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strndup(const char *s1, size_t n)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = ft_memalloc(sizeof(char) * (n + 1));
	if (res == NULL)
		return (NULL);
	while (i < n)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
