/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:22:32 by cterrill          #+#    #+#             */
/*   Updated: 2017/05/29 18:01:21 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*new_s1;
	unsigned char	*new_s2;
	size_t			i;

	new_s1 = (unsigned char*)s1;
	new_s2 = (unsigned char*)s2;
	i = 0;
	while (s1[i] && new_s1[i] == new_s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (new_s1[i] - new_s2[i]);
}
