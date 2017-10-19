/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 12:05:48 by cterrill          #+#    #+#             */
/*   Updated: 2017/05/14 19:51:19 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int		i;
	int		j;
	char	*new;

	if (!s)
		return (NULL);
	i = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	i = ft_strlen(s) - 1;
	if (i == -1)
		return (ft_strnew(0));
	while (!s[i] || s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	new = ft_strnew(++i);
	if (!new)
		return (NULL);
	j = i;
	i = 0;
	while (i < j)
	{
		new[i] = s[i];
		i++;
	}
	return (new);
}
