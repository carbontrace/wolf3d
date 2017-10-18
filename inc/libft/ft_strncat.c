/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:12:18 by cterrill          #+#    #+#             */
/*   Updated: 2017/02/27 16:12:30 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	char *iter;

	iter = dest;
	while (*iter != 0)
		iter++;
	while (*src != 0 && nb-- != 0)
		*iter++ = *src++;
	*iter = 0;
	return (dest);
}
