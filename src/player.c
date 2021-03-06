/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:53:38 by cterrill          #+#    #+#             */
/*   Updated: 2017/10/18 20:20:18 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

t_coord		*newcoord(double x, double y)
{
	t_coord *coord;

	coord = malloc(sizeof(t_coord));
	coord->x = x;
	coord->y = y;
	return (coord);
}

double		d2r(double d)
{
	return (M_PI * d / 180);
}

void		adjustplane(t_player *p, double fov)
{
	double	fx;
	double	fy;
	double	px;
	double	py;

	fx = p->dir->x;
	fy = p->dir->y;
	px = (int)(fx * cos(d2r(90)) - fy * sin(d2r(90)));
	py = (int)(fx * sin(d2r(90)) + fy * cos(d2r(90)));
	p->plane = newcoord(fov * px, fov * py);
}

t_player	*newplayer(double x, double y)
{
	t_player *player;

	player = malloc(sizeof(t_player));
	player->pos = newcoord(x, y);
	player->dir = newcoord(0, 1);
	adjustplane(player, 0.66);
	return (player);
}
