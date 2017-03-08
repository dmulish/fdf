/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:21:05 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/08 20:37:28 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_hook(int key, t_v *v)
{
	(void)v;
	printf("key: %d\n", key);
	if (key == 53)
		exit(0);
	return (0);
}

int		exit_hook(void)
{
	exit(0);
	return (0);
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
		//mlx_pixel_put(v->mlx, v->win, tmp->x1, tmp->y1, 0x1484a0);
		line(tmp, v);
		tmp = tmp->next;
	}
}

int		loop_hook(t_v *v)
{
	draw(v);
	return (0);
}

void	draw_grid(t_v *v, char *name)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, W, H, name);
	mlx_key_hook(v->win, key_hook, v);
	//mlx_mouse_hook(v->win, mouse_hook, v);
	mlx_loop_hook(v->mlx, loop_hook, v);
	mlx_hook(v->win, 17, 0, exit_hook, 0);
	mlx_loop(v->mlx);
}
