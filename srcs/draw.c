/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:06:24 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/17 21:44:09 by dmulish          ###   ########.fr       */
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
		tmp->z1 = tmp->z * 10;
		tmp->x1 = (tmp->x + 1) * v->dist_x - (W / 2);
		tmp->y1 = (tmp->y + 1) * v->dist_y - (H / 2);
		x = tmp->x1;
		tmp->y1 = tmp->y1 * cos(0.7) + tmp->z1 * sin(0.7) + (H / 2);
		tmp->z1 = tmp->z1 * cos(0.7) - tmp->y1 * sin(0.7);
		z = tmp->z1;
		tmp->x1 = x * cos(0.3) + z * sin(0.3) + (W / 2);
		tmp->z1 = z * cos(0.3) - x * sin(0.3);
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
