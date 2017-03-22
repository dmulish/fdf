/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:06:24 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/22 18:18:30 by dmulish          ###   ########.fr       */
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
	int		z;
	t_lst	*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp->z1 = -tmp->z * 5;
		tmp->x1 = (tmp->x + 1) * v->dist_x - (W / 2);
		tmp->y1 = (tmp->y + 1) * v->dist_y - (H / 2);
		x = tmp->x1;
		tmp->y1 = tmp->y1 * cos(RAD(90)) + tmp->z1 * sin(RAD(90)) + (H / 2);
		tmp->z1 = tmp->z1 * cos(RAD(90)) - tmp->y1 * sin(RAD(90));
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
	v->dist_x = W / (v->max_x + 2);
	v->dist_y = H / (v->max_y + 1);
	tmp = rot(tmp, v);
	while (tmp)
	{
		if (tmp->next && tmp->x != v->max_x)
			line(tmp, tmp->next, v);
		line(tmp, next_y(tmp, v->max_x + 1), v);
		tmp = tmp->next;
	}
}
