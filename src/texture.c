/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:53:09 by cterrill          #+#    #+#             */
/*   Updated: 2017/10/18 20:19:36 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	load_sprites(t_env *e)
{
	e->sprite[0] = (t_sprite){3.5, 30.5, 1};
	e->sprite[1] = (t_sprite){6.5, 12.5, 1};
	e->sprite[2] = (t_sprite){4.3, 8.3, 1};
	e->sprite[3] = (t_sprite){200.5, 2.5, 1};
	e->sprite[4] = (t_sprite){4.5, 9.5, 1};
	e->sprite[5] = (t_sprite){65.5, 6.5, 1};
	e->sprite[6] = (t_sprite){3.5, 6.5, 1};
	e->sprite[7] = (t_sprite){29.5, 5, 1};
}

void	texture_sprite_load(t_env *e)
{
	int	width;
	int	height;

	e->spr[0] = mlx_xpm_file_to_image(e->mlx,
			"gfx/sprite1.xpm", &width, &height);
	e->spr[1] = mlx_xpm_file_to_image(e->mlx,
			"gfx/ghost.xpm", &width, &height);
}

void	texture_load(t_env *e)
{
	int		width;
	int		height;

	e->wall[0] = mlx_xpm_file_to_image(e->mlx,
			"gfx/tex_floor_tile_darkgray.xpm", &width, &height);
	e->wall[1] = mlx_xpm_file_to_image(e->mlx,
			"gfx/tex_ceiling_castle.xpm", &width, &height);
	e->wall[2] = mlx_xpm_file_to_image(e->mlx,
			"gfx/tex_wall_castle.xpm", &width, &height);
	e->wall[3] = mlx_xpm_file_to_image(e->mlx,
			"gfx/tex_wall_castle2.xpm", &width, &height);
	e->wall[4] = mlx_xpm_file_to_image(e->mlx,
			"gfx/tex_wall_castle_door.xpm", &width, &height);
	texture_sprite_load(e);
}
