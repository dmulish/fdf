/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:06:24 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/17 16:26:59 by dmulish          ###   ########.fr       */
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

void	draw(t_v *v)
{
	t_lst	*tmp;

	tmp = v->el;
	v->dist_x = W / (v->max_x + 1);
	v->dist_y = H / (v->max_y + 1);
	while (tmp)
	{
		tmp->x1 = (tmp->x + 0.5) * v->dist_x;
		tmp->y1 = (tmp->y + 1) * v->dist_y;
		if (tmp->next && tmp->x != v->max_x)
			line(tmp, tmp->next, v);
		line(tmp, next_y(tmp, v->max_x + 1), v);
		tmp = tmp->next;
	}
}
