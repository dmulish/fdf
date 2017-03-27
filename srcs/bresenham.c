/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:11:44 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/27 16:56:40 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_d		*new_d(t_lst *d0, t_lst *d1, t_v *v)
{
	t_d	*d;

	(void)v;
	if (d1)
	{
		if (!(d = (t_d*)malloc(sizeof(t_d))))
			return (0);
		d->x0 = d0->x1;
		d->y0 = d0->y1;
		d->x1 = d1->x1;
		d->y1 = d1->y1;
		d->z0 = d0->z;
		d->z1 = d1->z;
		d->dx = 0;
		d->dy = 0;
		d->s = 0;
		d->step = 0;
		d->error = 0;
		return (d);
	}
	return (0);
}

void	check(t_d *d)
{
	d->s = abs(d->y1 - d->y0) > abs(d->x1 - d->x0);
	if (d->s)
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

void	line(t_lst *d0, t_lst *d1, t_v *v)
{
	int	x;
	int	y;
	t_d	*d;

	if (d0 == NULL || d1 == NULL)
		return ;
	d = new_d(d0, d1, v);
	check(d);
	d->dx = d->x1 - d->x0;
	d->dy = abs(d->y1 - d->y0);
	d->error = d->dx / 2;
	d->step = (d->y0 < d->y1) ? 1 : -1;
	x = d->x0 - 1;
	y = d->y0;
	while (++x <= d->x1)
	{
		if (d->z0 == d->z1)
			mlx_pixel_put(v->mlx, v->win, d->s ? y : x, d->s ? x : y,
					set_col(d0, d0->col));
		else
			mlx_pixel_put(v->mlx, v->win, d->s ? y : x, d->s ? x : y,
					set_col(d1, d1->col));
		d->error -= d->dy;
		if (d->error < 0)
		{
			y += d->step;
			d->error += d->dx;
		}
	}
	free(d);
}
