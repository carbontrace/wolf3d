/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 20:33:02 by cterrill          #+#    #+#             */
/*   Updated: 2017/10/18 20:33:09 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <stdio.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

/*
** CONSTANTS
*/

# define WIDTH 640
# define HEIGHT 480

# define TEX_COUNT 5
# define SPR_COUNT 2
# define HUD_COUNT 8

# define NBSPRITE 15

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_SPACEBAR 49

# define MOVESPEED 0.1
# define ROTSPEED 0.1

# define CR cos(ROTSPEED)
# define SR sin(ROTSPEED)
# define C_R cos(-ROTSPEED)
# define S_R sin(-ROTSPEED)

/*
** STRUCTS
*/

typedef struct	s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct	s_map
{
	int			**wall;
	int			x;
	int			y;
}				t_map;

typedef struct	s_player
{
	t_coord		*pos;
	t_coord		*dir;
	t_coord		*plane;
}				t_player;

typedef struct	s_img
{
	int			width;
	int			height;
	char		*buffer;
}				t_img;

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			texture;
}				t_sprite;

typedef struct	s_keyboard
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			sleft;
	int			sright;
}				t_keyboard;

typedef struct	s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}				t_mouse;

typedef struct	s_hud
{
	int			camx;
	int			camy;
	int			w;
	int			h;
	int			texture;
	int			c;
	int			nb;
}				t_hud;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*imgpx;
	int			bpp;
	int			size_line;
	int			endian;
	t_map		*map;
	t_player	*player;
	t_img		*wall[TEX_COUNT];
	t_img		*spr[SPR_COUNT];
	t_hud		hud[HUD_COUNT];
	t_sprite	sprite[NBSPRITE];
	t_keyboard	key;
	t_mouse		mouse;
}				t_env;

typedef struct	s_raycast
{
	double		camerax;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	double		mapx;
	double		mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		stepx;
	double		stepy;
	double		perpwalldist;
	int			hit;
	int			side;
	double		zbuffer[WIDTH];
}				t_raycast;

typedef struct	s_ray
{
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			x;
	int			y;
	double		wallx;
	int			texx;
	int			texy;

	double		floorxwall;
	double		floorywall;
	double		distwall;
	double		distplayer;
	double		currentdist;
	double		weight;

	double		currentfloorx;
	double		currentfloory;

	int			floortexx;
	int			floortexy;
}				t_ray;

typedef struct	s_raysprite
{
	int			i;
	double		spritex;
	double		spritey;
	double		invdet;
	double		tx;
	double		ty;
	int			spritescreenx;
	int			spriteheight;
	int			drawstarty;
	int			drawendy;
	int			spritewidth;
	int			drawstartx;
	int			drawendx;
	int			stripe;
	int			y;
	int			texx;
	int			d;
	int			texy;
}				t_raysprite;

void			render_init(t_player *player, t_map *map, int room);
int				wolf_init(int room, char *file);
int				key_press_hook(int keycode, t_env *e);
int				key_release_hook(int keycode, t_env *e);

int				expose_hook(t_env *e);
int				refresh_hook(t_env *e);

t_list			*read_file(char	*filepath);
t_map			*map_parse(t_list	*list);
void			map_print(t_map	*map);

t_player		*newplayer(double x, double y);
t_coord			*newcoord(double x, double y);
void			raycast(t_env *e);

void			draw_dot(t_env *e, int x, int y, int color);
int				rgb2i(int r, int g, int b);
int				getcolor(t_img *img, int x, int y, int fade);
void			drawbyside(t_env *e, t_raycast *rc, int x, int y);

void			texture_load(t_env *e);
void			load_sprites(t_env *e);
void			initkeyboard(t_env *e);
void			key_press(t_keyboard *key, int keycode);
void			key_release(t_keyboard *key, int keycode);
void			key_up_down(t_env *e);
void			key_left_right(t_env *e);

int				hook_mousemove(int x, int y, t_env *env);

void			draw_ray(t_raycast *rc, int x, t_env *e);
void			ray_sprite(t_env *e, t_raysprite *rs);
void			draw_sprite(t_env *e, t_raycast *rc, t_raysprite *rs);

void			render(t_env *e);
int				exit_hook(void);

#endif
