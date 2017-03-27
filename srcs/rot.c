/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:25:44 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/27 16:10:08 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
		x = tmp->x1;
		tmp->y1 = (tmp->y) * v->dist_y - (H / 2);
		y = tmp->y1;
		tmp->z1 = -tmp->z * v->mult_z;
		tmp->y1 = y * cos(v->alpha) + tmp->z1 * sin(v->alpha);
		tmp->z1 = tmp->z1 * cos(v->alpha) - y * sin(v->alpha);
		z = tmp->z1;
		tmp->x1 = x * cos(v->beta) + z * sin(v->beta);
		tmp->z1 = z * cos(v->beta) - x * sin(v->beta);
		x = tmp->x1;
		y = tmp->y1;
		tmp->x1 = x * cos(v->gamma) + y * sin(v->gamma) + (W / 2) + v->dx;
		tmp->y1 = y * cos(v->gamma) - x * sin(v->gamma) + (H / 2) + v->dy;
		tmp->x1 *= v->zoom;
		tmp->y1 *= v->zoom;
		tmp = tmp->next;
	}
	return (lst);
}
