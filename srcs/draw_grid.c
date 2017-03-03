/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:21:05 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/03 21:05:33 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_hook(int key, t_v *e)
{
	(void)e;
	printf("key: %d\n", key);
	if (key == 53)
		exit(0);
	return (0);
}

int		mouse_hook(int button, int a, int b, t_v *e)
{
	(void)e;
	printf("button: %d(%d : %d)\n", button, a, b);
	return (0);
}

void	draw(t_v *v)
{
	mlx_pixel_put(v->mlx, v->win, 600, 600, 0xffffff);
}

int		expose_hook(t_v *v)
{
	draw(v);
	return (0);
}

void	draw_grid(t_lst *map, char *name)
{
	t_v	e;

	map = 0;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1200, 1200, name);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}
