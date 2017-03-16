/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 19:23:36 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/16 16:04:50 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	print_list(t_lst *list)
{
	while (list != NULL)
	{
		printf("x = %d	y = %d	z = %d\n", list->x, list->y, list->z);
		list = list->next;
	}
}

void	init(t_v *v)
{
	v->max_x = 0;
}

int		main(int argc, char **argv)
{
	int		fd;
	t_v		v;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf your_map\n");
		return (0);
	}
	init(&v);
	v.el = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	v.el = map_read(v.el, fd, &v);
	if (v.el == 0)
	{
		ft_putstr("Error: Invalid map\n");
		return (0);
	}
	draw_grid(&v, argv[1]);
	return (0);
}
