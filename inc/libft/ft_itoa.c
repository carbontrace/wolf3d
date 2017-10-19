/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:55:26 by cterrill          #+#    #+#             */
/*   Updated: 2017/05/29 17:55:33 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	intlen(int n)
{
	size_t		i;

	i = 1;
	if (n < 0)
		i++;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char		*res;
	size_t		len;
	int			flag;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = intlen(n);
	if (!(res = ft_strnew(len)))
		return (NULL);
	if (n < 0)
	{
		*res = '-';
		n *= -1;
		flag = 1;
	}
	else
		flag = 0;
	while (len--)
	{
		if (n || !flag)
			res[len] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
