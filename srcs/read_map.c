/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:15:20 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/02 20:58:20 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_lst	*new_elem(char *arr, int i, int j)
{
	t_lst	*el;

	if ((el = (t_lst*)malloc(sizeof(t_lst))) == NULL)
		return (0);
	el->x = i;
	el->y = j;
	el->z = ft_atoi(arr);
	el->next = NULL;
	return (el);
}

t_lst	*add_to_lst(t_lst **old, t_lst *elem)
{
	t_lst	*new;

	if ((new = (t_lst*)malloc(sizeof(t_lst))) == NULL)
		return (0);
	if (!old)
		return (new);
	new = elem;
	new->next = *old;
	*old = new;
	return (new);
}

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
			lst = add_to_lst(&lst, new_elem(arr[i], i, j));
		v->max_x = i;
	}
	else
	{
		while (arr[++i] && i <= v->max_x)
			lst = add_to_lst(&lst, new_elem(arr[i], i, j));
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
		j++;
	}
	return (list);
}
