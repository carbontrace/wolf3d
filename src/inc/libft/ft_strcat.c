/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:09:52 by cterrill          #+#    #+#             */
/*   Updated: 2017/04/23 14:43:36 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char *iter;

	iter = s1;
	while (*iter != 0)
		iter++;
	while (*s2 != 0)
		*iter++ = *s2++;
	*iter = *s2;
	return (s1);
}
