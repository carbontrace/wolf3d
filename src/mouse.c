/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 18:06:28 by cterrill          #+#    #+#             */
/*   Updated: 2017/10/07 18:06:29 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		hook_mousedown(t_env *env, int button, int x, int y)
{
	if (button == 4)
	{
		//zoom(x, y, &mlx->viewport, 1 / ZOOM);
		//render(mlx);
    (void)x;
	}
	else if (button == 5)
	{
		//zoom(x, y, &mlx->viewport, ZOOM);
		//r//ender(mlx);
    (void)y;
	}
	if (y < 0)
		return (0);
	env->mouse.isdown = button;
	return (0);
}

int		hook_mouseup(t_env *env, int button, int x, int y)
{
	(void)x;
	(void)y;
	env->mouse.isdown = button;
	return (0);
}

int		hook_mousemove(int x, int y, t_env *e)
{
  double olddirx;
	double oldplanex;

  olddirx = e->player->dir->x;
	oldplanex = e->player->plane->x;

	e->mouse.lastx = e->mouse.x;
	e->mouse.lasty = e->mouse.y;
	e->mouse.x = x;
	e->mouse.y = y;

  if (e->mouse. x < WIDTH / 2)
	{
		e->player->dir->x = e->player->dir->x * C_R - e->player->dir->y * S_R;
		e->player->dir->y = olddirx * S_R + e->player->dir->y * C_R;
		e->player->plane->x = e->player->plane->x
			* C_R - e->player->plane->y * S_R;
		e->player->plane->y = oldplanex * S_R + e->player->plane->y * C_R;
	}

  if (e->mouse. x > WIDTH / 2)
  {
    e->player->dir->x = e->player->dir->x * CR - e->player->dir->y * SR;
		e->player->dir->y = olddirx * SR + e->player->dir->y * CR;
		e->player->plane->x = e->player->plane->x
			* CR - e->player->plane->y * SR;
		e->player->plane->y = oldplanex * SR + e->player->plane->y * CR;
  }
	return (0);
}
