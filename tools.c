/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:30:42 by stvalett          #+#    #+#             */
/*   Updated: 2016/12/20 09:17:53 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_rgb(int r, int g, int b)
{
	int color;

	color = 0;
	color += ((r << 16) + (g << 8) + b);
	return (color);
}

int		ft_lstcount(t_list_line *list)
{
	int count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

int		ft_check_file(char *av)
{
	int		i;
	char	*str;

	str = ".fdf";
	i = 0;
	while (av[i])
	{
		if (av[i] == '.')
		{
			if ((ft_strcmp(str, &av[i])) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}
