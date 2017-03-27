/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 18:33:10 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/24 18:59:19 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	iso(t_v *v)
{
	v->alpha = RAD(90);
	v->beta = RAD(77);
	v->gamma = RAD(-60);
	v->zoom = 1;
}