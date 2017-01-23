/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:45:13 by stvalett          #+#    #+#             */
/*   Updated: 2016/12/19 19:11:19 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move(int keycode, t_env *e)
{
	if (keycode == T_RIGHT)
		e->m_x += 10;
	else if (keycode == T_LEFT)
		e->m_x -= 10;
	else if (keycode == T_UP)
		e->m_y += 10;
	else if (keycode == T_DOWN)
		e->m_y -= 10;
}

void	ft_zoom(int keycode, t_env *e)
{
	if (keycode == T_H1)
		e->heigth_z += 1;
	else if (keycode == T_H2)
		e->heigth_z -= 1;
	else if (keycode == T_P)
	{
		e->scale_w += 1;
		e->scale_h += 1;
	}
	else if (keycode == T_M)
	{
		e->scale_w -= 1;
		e->scale_h -= 1;
	}
}

void	ft_key_rot_x(int key, t_env *e)
{
	if (key == ROT_X)
	{
		e->rot = 1;
		e->angle += 1;
	}
	else if (key == ROT_XX)
	{
		e->rot = 1;
		e->angle -= 1;
	}
}

void	ft_key_rot_y(int key, t_env *e)
{
	if (key == ROT_Y)
	{
		e->rot = 2;
		e->angle += 1;
	}
	else if (key == ROT_YY)
	{
		e->rot = 2;
		e->angle -= 1;
	}
}
