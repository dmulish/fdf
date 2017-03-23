/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:06:24 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/23 16:31:29 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_lst	*next_y(t_lst *orig, int max_x)
{
	t_lst	*tmp;

	tmp = orig;
	while (max_x-- > 0 && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_lst	*rot(t_lst *lst, t_v *v)
{
	int		x;
	int		y;
	int		z;
	t_lst	*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp->x1 = (tmp->x) * v->dist_x - (W / 2);
		tmp->y1 = (tmp->y) * v->dist_y - (H / 2);
		tmp->z1 = -tmp->z * 5;
		x = tmp->x1;
		y = tmp->y1;
		tmp->y1 = y * cos(RAD(90)) + tmp->z1 * sin(RAD(90)) + (H / 2);
		tmp->z1 = tmp->z1 * cos(RAD(90)) - y * sin(RAD(90));
		z = tmp->z1;
		tmp->x1 = x * cos(RAD(60)) + z * sin(RAD(60)) + (W / 2);
		tmp->z1 = z * cos(RAD(60)) - x * sin(RAD(60));
		tmp = tmp->next;
	}
	return (lst);
}

void	draw(t_v *v)
{
	t_lst	*tmp;

	tmp = v->el;
	v->dist_x = (double)W / (double)(v->max_x + 2);
	v->dist_y = (double)H / (double)(v->max_y + 1);
	tmp = rot(tmp, v);
	while (tmp)
	{
		if (tmp->next && tmp->x != v->max_x + 1.0)
			line(tmp, tmp->next, v);
		line(tmp, next_y(tmp, v->max_x + 1.0), v);
		tmp = tmp->next;
	}
}
