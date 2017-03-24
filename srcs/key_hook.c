/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:13:40 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/24 20:47:44 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int key, t_v *v)
{
	printf("key: %d\n", key);
	(key == 0) ? v->beta += RAD(10) : v->rand;
	(key == 1) ? v->alpha -= RAD(10) : v->rand;
	(key == 2) ? v->beta -= RAD(10) : v->rand;
	(key == 6) ? zero_angles(v) : v->rand;
	(key == 12) ? v->gamma += RAD(10) : v->rand;
	(key == 13) ? v->alpha += RAD(10) : v->rand;
	(key == 14) ? v->gamma -= RAD(10) : v->rand;
	(key == 24) ? v->zoom += 0.05 : v->rand;
	(key == 27) ? v->zoom -= 0.05: v->rand;
	(key == 34) ? iso(v) : v->rand;
	(key == 53) ? exit(0) : v->rand;
	(key == 123) ? v->dx += 5: v->rand;
	(key == 124) ? v->dx -= 5: v->rand;
	(key == 125) ? v->dy -= 5: v->rand;
	(key == 126) ? v->dy += 5: v->rand;
	return (0);
}
