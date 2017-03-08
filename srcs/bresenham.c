/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:53:12 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/08 20:37:42 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_d	*new_list(t_lst *dot)
{
	t_d	*d;

	if (dot->next)
	{
		if (!(d = (t_d*)malloc(sizeof(t_d))))
			return (0);
		d->x0 = dot->x1;
		d->y0 = dot->y1;
		d->x1 = dot->next->x1;
		d->y1 = dot->next->y1;
		return (d);
	}
	return (0);
}

void		check(t_d *d)
{
	if (abs(d->y1 - d->y0) > abs(d->x1 - d->x0))
	{
		SWAP(d->x0, d->y0);
		SWAP(d->x1, d->y1);
	}
	if (d->x0 > d->x1)
	{
		SWAP(d->x0, d->x1);
		SWAP(d->y0, d->y1);
	}
}

void		line(t_lst *dot, t_v *v)
{
	t_d	*d;
	int	x;
	int	y;
	int	step;
	int	error;

	d = new_list(dot);
	if (dot->next)
	{
		check(d);
		dot->dx = dot->next->x1 - dot->x1;
		dot->dy = abs(dot->next->y1 - dot->y1);
		error = dot->dx / 2;
		step = (dot->y1 < dot->next->y1) ? 1 : -1;
		x = dot->x1;
		y = dot->y1;
		while (x <= dot->next->x1)
		{
			mlx_pixel_put(v->mlx, v->win, x, y, 0xffffff);
			error -= dot->dy;
			if (error < 0)
			{
				y += step;
				error += dot->dx;
			}
			x++;
		}
	}
	free(d);
}
