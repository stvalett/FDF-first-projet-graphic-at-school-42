/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 08:51:57 by stvalett          #+#    #+#             */
/*   Updated: 2016/12/20 09:12:04 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(int ac)
{
	if (ac != 2)
	{
		ft_putendl("Usage : ./fdf name_map.fdf");
		exit(1);
	}
	return (0);
}

int		ft_error2(char **av)
{
	if (ft_check_file(av[1]) == 0)
	{
		ft_putendl("Error file");
		ft_putendl("Usage : ./fdf name_map.fdf");
		exit(1);
	}
	return (0);
}
