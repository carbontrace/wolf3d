/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 12:02:37 by cterrill          #+#    #+#             */
/*   Updated: 2017/05/29 18:04:43 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		s1l;
	int		s2l;
	int		i;

	i = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	s3 = ft_strnew((s1l + s2l));
	if (!s3)
		return (NULL);
	while (*s1)
		s3[++i] = *s1++;
	while (*s2)
		s3[++i] = *s2++;
	s3[++i] = '\0';
	return (s3);
}
