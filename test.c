/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 12:06:15 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/04 20:23:53 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

void	draw(void *mlx, void *win)
{
	int		x;
	int		y;
	
	y = 99;
	while (++y < 200)
	{
		x = 99;
		while (++x < 200)
			mlx_pixel_put(mlx, win, x, y, 0x009999);
	}
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	printf("button: %d (%d : %d)\n", button, x, y);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	printf("key: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 300, 300, "my first window");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	draw(e.mlx, e.win);
	//mlx_string_put(mlx, win, 100, 100, 0x009999, "string");
	mlx_loop(e.mlx);
	return (0);
}
