/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:58:49 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/01/22 15:20:43 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		key_press_hook(int keycode, t_env *e)
{
	key_press(&e->key, keycode);
	if (keycode == KEY_ESC)
	{
		system("killall afplay 2> /dev/null");
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_SPACEBAR)
		e->hud[0].c++;
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
