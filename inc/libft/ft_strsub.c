/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 12:05:33 by cterrill          #+#    #+#             */
/*   Updated: 2017/05/29 17:52:04 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	new = ft_strnew(len);
	i = 0;
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	return (new);
}
