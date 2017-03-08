/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 13:44:17 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/05 13:48:31 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_dots	*new_dot_list(t_dots *dot)
{
	if ((dot = (t_dots*)malloc(sizeof(t_dots))) == NULL)
		return (0);
	dot->x = 0;
	dot->y = 0;
	dot->dist_x = 0;
	dot->dist_y = 0;
	return (dot);
}
