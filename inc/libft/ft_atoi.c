/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 11:08:29 by cterrill          #+#    #+#             */
/*   Updated: 2017/05/29 18:05:18 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	res;

	sign = 1;
	res = 0;
	while (*str == '\n' || *str == '\t' || *str == '\r' || *str == '\v' ||
		*str == '\f' || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		res = (res * 10) + *str++ - '0';
		if (res >= 9223372036854775807 && sign == 1)
			return (-1);
		if (res > 9223372036854775807 && sign == -1)
			return (0);
	}
	return (res * sign);
}
