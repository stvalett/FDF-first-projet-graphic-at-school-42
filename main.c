/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:23:47 by stvalett          #+#    #+#             */
/*   Updated: 2016/12/20 09:12:00 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	int	length;
	int	width;
	int	fd;
	int	**tab;

	width = 0;
	length = 0;
	if (ac != 2)
		ft_error(ac);
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putendl("Error open file()");
		return (1);
	}
	if (ft_check_file(av[1]) == 0)
		ft_error2(av);
	else
	{
		tab = ft_get_tab(fd, &length, &width);
		ft_mlx(tab, length, width);
		close(fd);
	}
	return (0);
}
