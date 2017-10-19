
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
#include "./libft.h"
# include <limits.h>

int get_next_line(const int fd, char **line);

typedef struct	s_fbuff
{
	int			fd;
	char		*start;
	char		*str;
}				t_fbuff;

#endif
