/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:13:40 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/25 15:22:04 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int key, t_v *v)
{
	printf("key: %d\n", key);
	(key == 0) ? v->beta += RAD(10) : v->beta;
	(key == 1) ? v->alpha -= RAD(10) : v->alpha;
	(key == 2) ? v->beta -= RAD(10) : v->beta;
	(key == 6) ? zero_angles(v) : v->rand;
	(key == 12) ? v->gamma += RAD(10) : v->gamma;
	(key == 13) ? v->alpha += RAD(10) : v->alpha;
	(key == 14) ? v->gamma -= RAD(10) : v->gamma;
	(key == 24) ? v->zoom += 0.05 : v->zoom;
	(key == 27) ? v->zoom -= 0.05 : v->zoom;
	(key == 34) ? iso(v) : v->rand;
	(key == 53) ? exit(0) : v->rand;
	(key == 123) ? v->dx -= 10: v->dx;
	(key == 124) ? v->dx += 10: v->dx;
	(key == 125) ? v->dy += 10: v->dy;
	(key == 126) ? v->dy -= 10: v->dy;
	return (0);
}
