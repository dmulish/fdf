/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:06:24 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/27 15:46:38 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_lst	*next_y(t_lst *orig, int max_x)
{
	t_lst	*tmp;

	tmp = orig;
	while (max_x-- > 0 && tmp)
		tmp = tmp->next;
	return (tmp);
}

void	tips(t_v *v)
{
	mlx_string_put(v->mlx, v->win, 200, 10, 0x468b78, "Iso: I");
	mlx_string_put(v->mlx, v->win, 200, 30, 0x468b78, "Grid: Z");
	mlx_string_put(v->mlx, v->win, 10, 10, 0x468b78, "Zoom: + -");
	mlx_string_put(v->mlx, v->win, 10, 30, 0x468b78, "Move: arrows");
	mlx_string_put(v->mlx, v->win, 10, 50, 0x468b78, "Rotate: W A S D");
}

void	draw(t_v *v)
{
	t_lst	*tmp;

	tmp = v->el;
	v->dist_x = (double)W / (double)(v->max_x + 2);
	v->dist_y = (double)H / (double)(v->max_y + 1);
	tmp = rot(tmp, v);
	tips(v);
	while (tmp)
	{
		if (tmp->next && tmp->x != v->max_x + 1)
			line(tmp, tmp->next, v);
		line(tmp, next_y(tmp, v->max_x + 1), v);
		tmp = tmp->next;
	}
}
