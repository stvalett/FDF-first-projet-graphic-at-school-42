/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:30:03 by stvalett          #+#    #+#             */
/*   Updated: 2016/12/19 18:42:09 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	t_bress		*ft_init_bres(t_coord *p1, t_coord *p2)
{
	t_bress *bres;

	if ((bres = (t_bress *)malloc(sizeof(t_bress))) == NULL)
		return (NULL);
	bres->x1 = ft_abs(p2->x - p1->x);
	bres->x2 = (p1->x < p2->x) ? 1 : -1;
	bres->y1 = ft_abs(p2->y - p1->y);
	bres->y2 = (p1->y < p2->y) ? 1 : -1;
	bres->error = (bres->x1 > bres->y1 ? bres->x1 : -(bres->y1)) / 2;
	return (bres);
}

void				ft_draw(t_env *env, t_coord *p1, t_coord *p2)
{
	int		x;
	int		y;
	int		ret;
	t_bress	*bres;

	bres = ft_init_bres(p1, p2);
	x = p1->x;
	y = p1->y;
	while (1)
	{
		ft_put_pixel(env, x, y);
		if (x == p2->x && y == p2->y)
			break ;
		if ((ret = bres->error) > -(bres->x1))
		{
			bres->error -= bres->y1;
			x += bres->x2;
		}
		if (ret < bres->y1)
		{
			bres->error += bres->x1;
			y += bres->y2;
		}
	}
}
