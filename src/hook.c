/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:55:19 by cterrill          #+#    #+#             */
/*   Updated: 2017/10/18 19:55:21 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		key_press_hook(int keycode, t_env *e)
{
	key_press(&e->key, keycode);
	if (keycode == KEY_ESC)
	{
		exit_hook();
	}
	if (keycode == KEY_SPACEBAR)
		system("afplay sfx/sfx_heart.wav &");
	return (0);
}

int		key_release_hook(int keycode, t_env *e)
{
	key_release(&e->key, keycode);
	return (0);
}

int		expose_hook(t_env *e)
{
	render(e);
	return (0);
}

int		exit_hook(void)
{
	system("killall afplay 2> /dev/null");
	exit(1);
	return (0);
}

int		refresh_hook(t_env *e)
{
	render(e);
	usleep(5000);
	return (0);
}
