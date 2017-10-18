/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 22:16:04 by cterrill          #+#    #+#             */
/*   Updated: 2017/04/22 22:18:30 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char *p1;
	char *p2;

	if (!str || !*str)
		return (str);
	p1 = str;
	p2 = str + ft_strlen(str);
	while (p2 > p1)
		ft_swapchar(p1++, p2--);
	return (str);
}
