/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:15:20 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/25 17:17:24 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_lst	*push_back(t_lst *old, t_lst *new1)
{
	t_lst	*cur;

	if (!old)
		return (new1);
	cur = old;
	while (cur->next)
		cur = cur->next;
	cur->next = new1;
	return (old);
}

t_lst	*fill_cord(char **arr, int j, t_v *v)
{
	int		i;
	t_lst	*lst;

	i = -1;
	lst = NULL;
	if (v->max_x == 0)
	{
		while (arr[++i])
			lst = push_back(lst, new_elem(arr[i], i, j));
		v->max_x = i - 1;
	}
	else
	{
		while (arr[++i] && i <= v->max_x)
			lst = push_back(lst, new_elem(arr[i], i, j));
		if (i <= v->max_x)
			return (0);
	}
	return (lst);
}

t_lst	*map_read(t_lst *list, int fd, t_v *v)
{
	int		j;
	char	*line;
	char	**arr;

	j = 0;
	list = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		arr = ft_strsplit(line, 32);
		list = push_back(list, fill_cord(arr, j, v));
		if (fill_cord(arr, j, v) == 0)
			return (0);
		j++;
	}
	v->max_y = j;
	return (list);
}
