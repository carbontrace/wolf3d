/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:53:50 by cterrill          #+#    #+#             */
/*   Updated: 2017/10/18 19:53:52 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

t_list	*read_file(char *filepath)
{
	t_list	*list;
	t_list	*l;
	char	*line;
	int		fd;

	list = NULL;
	if ((fd = open(filepath, O_RDONLY)))
	{
		while (get_next_line(fd, &line) > 0)
		{
			l = ft_lstnew(line, sizeof(char) * ft_strlen(line) + 1);
			ft_lstadd(&list, l);
			free(line);
		}
		if (list)
			return (list);
	}
	ft_putstr("no map or not readable");
	exit(EXIT_FAILURE);
}

int		atoi_free(char *tab)
{
	int	nb;

	nb = ft_atoi(tab);
	free(tab);
	return (nb);
}

t_map	*map_parse(t_list *list)
{
	t_map	*map;
	char	**tab;
	int		x;
	int		y;

	map = (t_map*)malloc(sizeof(t_map));
	if (list && map && !(y = 0))
	{
		map->y = ft_lstlen(list);
		map->wall = (int**)malloc(sizeof(int*) * map->y);
		while (list && (x = -1))
		{
			tab = ft_strsplit(list->content, ' ');
			free(list->content);
			map->x = ft_tablen(tab);
			map->wall[y] = (int*)malloc(sizeof(int) * map->x);
			while (++x < map->x)
				map->wall[y][x] = atoi_free(tab[x]);
			list = list->next;
			y++;
		}
	}
	return (map);
}

void	map_print(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			ft_putnbr(map->wall[y][x]);
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
