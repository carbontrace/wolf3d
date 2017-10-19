/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:34:01 by cterrill          #+#    #+#             */
/*   Updated: 2017/08/22 22:20:17 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read(const int fd, char **string)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		i;

	if ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		tmp = *string;
		*string = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (i);
}

int			get_next_line(const int fd, char **line)
{
	static char	*string[9001];
	char		*end_pos;
	int			j;

	if (fd < 0 || fd > INT_MAX - 1 || line == NULL)
		return (-1);
	if (!string[fd])
		string[fd] = ft_strnew(1);
	while ((end_pos = ft_strchr(string[fd], '\n')) == NULL)
	{
		if ((j = ft_read(fd, &string[fd])) < 0)
			return (-1);
		if (j == 0 && !end_pos)
		{
			if (string[fd][0] == '\0')
				return (0);
			*line = string[fd];
			string[fd] = NULL;
			return (1);
		}
	}
	*line = ft_strsub(string[fd], 0, end_pos - string[fd]);
	string[fd] = ft_strdup(end_pos + 1);
	return (1);
}
