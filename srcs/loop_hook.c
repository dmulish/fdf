/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:47:09 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/27 16:10:05 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_fl(t_v *v)
{
	(v->fl_l == 3) ? v->dx -= 10 : v->dx;
	(v->fl_r == 4) ? v->dx += 10 : v->dx;
	(v->fl_d == 5) ? v->dy += 10 : v->dy;
	(v->fl_u == 6) ? v->dy -= 10 : v->dy;
	(v->fl_ai == 7) ? v->alpha += RAD(10) : v->alpha;
	(v->fl_ad == 8) ? v->alpha -= RAD(10) : v->alpha;
	(v->fl_bi == 9) ? v->beta += RAD(10) : v->beta;
	(v->fl_bd == 10) ? v->beta -= RAD(10) : v->beta;
	(v->fl_gi == 11) ? v->gamma += RAD(10) : v->gamma;
	(v->fl_gd == 12) ? v->gamma -= RAD(10) : v->gamma;
	(v->fl_zin == 13) ? v->zoom += 0.02 : v->zoom;
	(v->fl_zout == 14) ? v->zoom -= 0.02 : v->zoom;
}

int		press_but(int key, t_v *v)
{
	printf("key: %d\n", key);
	(key == 0) ? v->fl_bi = 9 : v->beta;
	(key == 1) ? v->fl_ad = 8 : v->alpha;
	(key == 2) ? v->fl_bd = 10 : v->beta;
	(key == 6) ? zero_angles(v) : v->rand;
	(key == 12) ? v->fl_gi = 11 : v->gamma;
	(key == 13) ? v->fl_ai = 7 : v->alpha;
	(key == 14) ? v->fl_gd = 12 : v->gamma;
	(key == 24) ? v->fl_zin = 13 : v->fl_zin;
	(key == 27) ? v->fl_zout = 14 : v->fl_zout;
	(key == 34) ? iso(v) : v->rand;
	(key == 53) ? exit(0) : v->rand;
	(key == 123) ? v->fl_l = 3 : v->fl_l;
	(key == 124) ? v->fl_r = 4 : v->fl_r;
	(key == 125) ? v->fl_d = 5 : v->fl_d;
	(key == 126) ? v->fl_u = 6 : v->fl_u;
	return (0);
}

int		release_but(int key, t_v *v)
{
	(key == 0) ? v->fl_bi = 0 : v->fl_bi;
	(key == 1) ? v->fl_ad = 0 : v->fl_ad;
	(key == 2) ? v->fl_bd = 0 : v->fl_bd;
	(key == 12) ? v->fl_gi = 0 : v->fl_gi;
	(key == 13) ? v->fl_ai = 0 : v->fl_ai;
	(key == 14) ? v->fl_gd = 0 : v->fl_gd;
	(key == 24) ? v->fl_zin = 0 : v->fl_zin;
	(key == 27) ? v->fl_zout = 0 : v->fl_zout;
	(key == 123) ? v->fl_l = 0 : v->fl_l;
	(key == 124) ? v->fl_r = 0 : v->fl_r;
	(key == 125) ? v->fl_d = 0 : v->fl_d;
	(key == 126) ? v->fl_u = 0 : v->fl_u;
	return (0);
}

int		loop_hook(t_v *v)
{
	check_fl(v);
	mlx_hook(v->win, 2, 1, press_but, v);
	mlx_hook(v->win, 3, 2, release_but, v);
	mlx_clear_window(v->mlx, v->win);
	draw(v);
	return (0);
}
