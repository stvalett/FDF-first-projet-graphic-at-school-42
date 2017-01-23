/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:48:57 by stvalett          #+#    #+#             */
/*   Updated: 2016/12/19 19:28:32 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_put_pixel(t_env *env, int x, int y)
{
	int res;

	res = ((env->bpp / 8) * x) + (env->sizeline * y);
	if (res >= 0 && res < HEIGTH * env->sizeline && res > y * env->sizeline
			&& res < (y * env->sizeline) + ((env->bpp / 8) * LENGTH))
	{
		env->data[res] = env->colors & 0XFF;
		env->data[res + 1] = (env->colors & 0XFFFF) >> 8;
		env->data[res + 2] = (env->colors & 0XFFFFFF) >> 16;
	}
}

static int		expose_hook(t_env *e)
{
	ft_bzero(e->data, HEIGTH * e->sizeline);
	ft_get_map(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}

static int		key_hook(int keycode, t_env *e)
{
	if (keycode == T_EXIT)
		exit(0);
	if (keycode == T_RIGHT || keycode == T_LEFT
			|| keycode == T_UP || keycode == T_DOWN)
		ft_move(keycode, e);
	else if (keycode == T_H1 || keycode == T_H2
			|| keycode == T_P || keycode == T_M)
		ft_zoom(keycode, e);
	else if (keycode == ROT_X || keycode == ROT_XX)
		ft_key_rot_x(keycode, e);
	else if (keycode == ROT_Y || keycode == ROT_YY)
		ft_key_rot_y(keycode, e);
	expose_hook(e);
	return (0);
}

static t_env	*ft_init_env(int **tab, int length, int heigth)
{
	t_env *e;

	if ((e = (t_env *)malloc(sizeof(t_env))) == NULL)
		return (NULL);
	if ((e->map = tab) == NULL)
		return (NULL);
	if ((e->mlx = mlx_init()) == NULL)
		return (NULL);
	if ((e->win = mlx_new_window(e->mlx, LENGTH, HEIGTH, "FDF@42")) == NULL)
		return (NULL);
	e->img_ptr = NULL;
	e->data = NULL;
	e->bpp = 0;
	e->sizeline = 0;
	e->heigth_z = HEIGTH_Z;
	e->x_length = length;
	e->y_heigth = heigth;
	e->scale_h = SCALE_H;
	e->scale_w = SCALE_W;
	e->m_x = 1;
	e->m_y = 1;
	e->angle = ANGLE;
	e->rot = 1;
	e->colors = ft_rgb(255, 255, 255);
	return (e);
}

int				ft_mlx(int **tab, int length, int width)
{
	t_env *e;

	if (!(e = ft_init_env(tab, length, width)))
		return (-1);
	if (!(e->img_ptr = mlx_new_image(e->mlx, LENGTH, HEIGTH)))
		return (-1);
	if (!(e->data = mlx_get_data_addr(e->img_ptr, &(e->bpp),
					&(e->sizeline), &(e->endian))))
		return (-1);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	mlx_hook(e->win, 2, 3, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
