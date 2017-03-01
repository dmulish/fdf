/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:15:20 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/01 20:19:07 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_e		*new_elem(char *arr, int i, int j)
{
	t_e	*el;

	if ((el = (t_e*)malloc(sizeof(t_e))) == NULL)
		return (0);
	el->x = i;
	el->y = j;
	el->z = ft_atoi(arr);
	return (el);
}

t_lst	*add_to_lst(t_lst **old, t_e *elem)
{
	t_lst	*new;

	if ((new = (t_lst*)malloc(sizeof(t_lst))) == NULL)
		return (0);
	new->cord = elem;
	new->next = NULL;
	if (!old)
		return (new);
	new->next = *old;
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

t_lst	*fill_cord(char **arr, int j)
{
	int		i;
	t_e		*el;
	t_lst	*lst;

	i = -1;
	lst = NULL;
	while (arr[++i])
		lst = add_to_lst(&lst, new_elem(arr[i], i, j));
	return (lst);
}

t_lst	*map_read(t_lst *list, int fd)
{
	int		j;
	char	*line;
	char	**arr;

	j = 0;
	list = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		arr = ft_strsplit(line, 32);
		list = push_back(list, fill_cord(arr, j));
		j++;
	}
	return (list);
}
