/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:55:11 by cterrill          #+#    #+#             */
/*   Updated: 2017/10/18 19:55:13 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"


int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_atoi(argv[1]) == 1)
		{
			wolf_init(1, "./map/tiny.w3d");
		}
		else if (ft_atoi(argv[1]) == 2)
		{
			wolf_init(2, "./map/lesstiny.w3d");
		}
	}
	else
	{
		ft_putstr("Usage: ./wolf3d [1/2]\n1. - Teeeeny tiny map\n2. - Less tiny map\n");
	}
	return (0);
}

int wolf_init(int room, char *file)
{
	t_map		*map;
	t_list		*list;
	t_player	*player;

	setbuf(stdout, NULL);
	list = read_file(file);
	map = map_parse(ft_lstrev(list));
	player = newplayer(2, 2);
	render_init(player, map, room);
	exit_hook();
	return (0);
}

void	render_init(t_player *player, t_map *map, int room)
{
	t_env	e;

	e.map = map;
	e.player = player;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "Wolf3d");
	texture_load(&e);
	load_sprites(&e);
	initkeyboard(&e);
	e.bpp = 0;
	e.size_line = 0;
	e.endian = 0;
	e.mouse.lastx = 0;
	e.mouse.lasty = 0;
	e.mouse.x = 0;
	e.mouse.y = 0;
	(room <= 1) ? system("afplay sfx/bgm_forest.mp3 &") : system("afplay sfx/bgm_spoopy.mp3 &");
	mlx_hook(e.win, 2, 1, key_press_hook, &e);
	mlx_hook(e.win, 3, 1, key_release_hook, &e);
	mlx_hook(e.win, 6, 1, hook_mousemove, &e);
	mlx_hook(e.win, 17, 0, exit_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop_hook(e.mlx, &refresh_hook, &e);
	mlx_loop(e.mlx);
}

void	render(t_env *e)
{
	key_up_down(e);
	key_left_right(e);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->imgpx = mlx_get_data_addr(e->img,
	&(e->bpp), &(e->size_line), &(e->endian));
	raycast(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}
