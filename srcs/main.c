/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 19:23:36 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/01 20:18:45 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	print_list(t_lst *list)
{
	while (list != NULL)
	{
		printf("x = %d, y = %d, z = %d\n", list->cord->x, list->cord->y,
				list->cord->z);
		list = list->next;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	t_lst	*list;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf your_map\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	list = map_read(list, fd);
	print_list(list);
	return (0);
}
