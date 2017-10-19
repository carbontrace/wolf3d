/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:54:16 by cterrill          #+#    #+#             */
/*   Updated: 2017/10/18 19:54:17 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		rgb2i(int r, int g, int b)
{
	int	color;

	color = 256 * 256 * r;
	color += 256 * g;
	color += b;
	return (color);
}

int		getcolor(t_img *img, int x, int y, int fade)
{
	int	color;
	int	c;

	fade /= 8;
	c = (y * img->width + x) * 4;
	color = img->buffer[c];
	if (color == -120 && img->buffer[c + 1] == 0 && img->buffer[c + 2] == -104)
		return (256 * 256 * 256 + 256 * 256 + 256);
	color += img->buffer[c + 1] * 256;
	color += img->buffer[c + 2] * 256 * 256;
	return (color);
}

void	draw_dot(t_env *e, int x, int y, int color)
{
	char	b;
	char	g;
	char	r;
	int		i;

	if (color == 256 * 256 * 256 + 256 * 256 + 256)
		return ;
	b = color % 256;
	g = (color / 256) % 256;
	r = (color / 256 / 256) % 256;
	i = (e->size_line * y) + (x * (e->bpp / 8));
	e->imgpx[i] = b;
	e->imgpx[i + 1] = g;
	e->imgpx[i + 2] = r;
}

void	drawbyside(t_env *e, t_raycast *rc, int x, int y)
{
	if (rc->raydiry > 0 && rc->side)
		draw_dot(e, x, y, 0xFF0000);
	if (rc->raydiry < 0 && rc->side)
		draw_dot(e, x, y, 0x00FF00);
	if (rc->raydirx > 0 && rc->side == 0)
		draw_dot(e, x, y, 0x0000FF);
	if (rc->raydirx < 0 && rc->side == 0)
		draw_dot(e, x, y, 0xAA00BB);
}
