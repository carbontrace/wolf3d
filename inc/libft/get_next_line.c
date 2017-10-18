/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 07:34:01 by cterrill          #+#    #+#             */
/*   Updated: 2017/08/17 18:58:37 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read(const int fd, char **s)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		i;

	if ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0'; //read returns the number of bytes read so this NULL-terminates the string in buf before
		tmp = *s; //sets tmp string to line in the array of strings
		*s = ft_strjoin(tmp, buf); //sets that line to a pointer to the new line
		free(tmp); //frees the space for tmp since s has been set
	}
	return (i); //returns the number of bytes read if it's over 0
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[9001];

	char		*end_s;
	int			k;

	if (fd < 0 || fd > INT_MAX - 1 || line == NULL) // error checking
		return (-1);
	if (!s[fd]) //if no string exists for current fd, make it
		s[fd] = ft_strnew(1);
	while ((end_s = ft_strchr(s[fd], '\n')) == NULL) //set end_s as the pointer to the \n or NULL if not found
	{
		if ((k = ft_read(fd, &s[fd])) < 0) //call ft_read and errror check
			return (-1);
		if (k == 0 && !end_s) //if reading no more bytes and end_s is 0
		{
			if (s[fd][0] == '\0') // if also the first char is a \0 then return 0 (no string)
				return (0);
			*line = s[fd]; // sets current line to string saved by fd
			s[fd] = NULL; // sets that string to NULL
			return (1); // returns that line was read
		}
	}
	*line = ft_strsub(s[fd], 0, end_s - s[fd]); // sets line to string that is as long as until the newline (end_s)
	s[fd] = ft_strdup(end_s + 1); // sets this string
	return (1);
}
