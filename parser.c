/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stvalett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 09:44:07 by stvalett          #+#    #+#             */
/*   Updated: 2016/12/19 19:31:52 by stvalett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list_line	*ft_init_list(void *data, size_t *content_size)
{
	t_list_line		*list;

	if ((list = (t_list_line *)malloc(sizeof(t_list_line))) == NULL)
		return (NULL);
	list->data = data;
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}

void		ft_fill_line(t_list_line **list, void *data, size_t *content_size)
{
	t_list_line		*tmp;

	tmp = *list;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_init_list(data, content_size);
	}
	else
		*list = ft_init_list(data, content_size);
}

t_list_line	*ft_get_list(int fd, int **length)
{
	char			*line;
	int				ret;
	t_list_line		*list;

	list = NULL;
	ret = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		**length = ft_strlen(line);
		ft_fill_line(&list, line, (size_t *)length);
	}
	return (list);
}

int			*ft_fill_tab(char **line, int **length)
{
	int i;
	int	res;
	int	*value;

	i = 0;
	res = 0;
	while (*(line + i))
		i++;
	res = i;
	if (res < **length)
		**length = res;
	value = (int *)malloc(sizeof(int) * res + 1);
	i = 0;
	while (i < res)
	{
		value[i] = ft_atoi(line[i]);
		i++;
	}
	return (value);
}

int			**ft_get_tab(int fd, int *length, int *width)
{
	t_list_line	*list;
	int			**tab;
	char		**line;
	int			i;

	list = ft_get_list(fd, &length);
	if (!list)
		return (0);
	tab = (int **)malloc(sizeof(int *) * ft_lstcount(list));
	i = 0;
	while (list)
	{
		line = ft_strsplit(list->data, ' ');
		tab[i] = ft_fill_tab(line, &length);
		i++;
		list = list->next;
	}
	*width = i;
	return (tab);
}
