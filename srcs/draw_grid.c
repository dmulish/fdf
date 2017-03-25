/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:21:05 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/25 15:59:14 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		exit_hook(void)
{
	exit(0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_v *v)
{
	(void)x;
	(void)y;
	printf("button: %d, pixel: (%d, %d)\n", button, x, y);
	(button == 4) ? v->mult_z -= 0.5 : v->mult_z;
	(button == 5) ? v->mult_z += 0.5 : v->mult_z;
	//(button == 6) ? v->beta += RAD(10) : v->beta;
	//(button == 7) ? v->beta -= RAD(10) : v->beta;
	return (0);
}

int		loop_hook(t_v *v)
{
	mlx_clear_window(v->mlx, v->win);
	draw(v);
	return (0);
}

void	draw_grid(t_v *v, char *name)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, W, H, name);
	mlx_key_hook(v->win, key_hook, v);
	mlx_mouse_hook(v->win, mouse_hook, v);
	mlx_hook(v->win, 17, 0, exit_hook, 0);
	mlx_loop_hook(v->mlx, loop_hook, v);
	mlx_loop(v->mlx);
}
