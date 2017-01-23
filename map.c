/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:01:53 by stvalett          #+#    #+#             */
/*   Updated: 2016/12/20 08:58:58 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	t_rot	*ft_init_rot(t_env *env, int x, int y, int z)
{
	t_rot	*rot;

	if ((rot = (t_rot *)malloc(sizeof(t_rot))) == NULL)
		return (NULL);
	rot->x_i = x;
	rot->y_i = y;
	rot->z_i = z - z;
	if (env->rot == 1)
		ft_rot_x(rot);
	else if (env->rot == 2)
		ft_rot_y(rot);
	return (rot);
}

static	t_coord	*ft_get_coord(t_env *env, int x, int y, int z)
{
	t_coord	*coord;
	t_rot	*rot;

	if ((coord = (t_coord *)malloc(sizeof(t_coord))) == NULL)
		return (NULL);
	rot = ft_init_rot(env, x, y, z);
	coord->x = (rot->x_f - rot->y_f) * env->scale_w + (LENGTH / 2)
		+ env->m_x;
	coord->y = (rot->y_f + rot->x_f) * env->scale_h -
		rot->z_f * env->angle - z * env->heigth_z + (HEIGTH / 32) + env->m_y;
	coord->z = rot->z_f;
	free(rot);
	return (coord);
}

void			ft_get_map(t_env *env)
{
	t_coord	*p1;
	t_coord	*p2;
	t_coord	*p3;
	int		x;
	int		y;

	y = -1;
	while (++y < env->y_heigth)
	{
		x = -1;
		while (++x < env->x_length)
		{
			p1 = ft_get_coord(env, x, y, env->map[y][x]);
			if (y + 1 < env->y_heigth)
			{
				p3 = ft_get_coord(env, x, (y + 1), env->map[y + 1][x]);
				ft_draw(env, p1, p3);
			}
			if (x + 1 < env->x_length)
			{
				p2 = ft_get_coord(env, (x + 1), y, env->map[y][x + 1]);
				ft_draw(env, p1, p2);
			}
		}
	}
}
