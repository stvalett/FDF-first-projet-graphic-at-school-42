/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 11:07:53 by stvalett          #+#    #+#             */
/*   Updated: 2016/12/19 20:42:30 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rot_x(t_rot *rot)
{
	rot->x_f = rot->x_i;
	rot->y_f = rot->y_i * cos(ANGLE) - rot->z_i * sin(ANGLE);
	rot->z_f = rot->y_i * sin(ANGLE) + rot->z_i * cos(ANGLE);
}

void	ft_rot_y(t_rot *rot)
{
	rot->x_f = rot->x_i * cos(ANGLE) + rot->z_i * sin(ANGLE);
	rot->y_f = rot->y_i;
	rot->z_f = -rot->x_i * sin(ANGLE) + rot->z_i * cos(ANGLE);
}
