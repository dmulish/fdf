/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 13:22:48 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/27 17:27:31 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	set_col(t_lst *lst, int col)
{
	static int	i;

	(void)lst;
	i = rand();
	//lst->r = ((col >> 16) & 0xff) / 255 + (20 * i);
	//lst->g = ((col >> 8) & 0xff) / 255 + (100 * i);
	//lst->b = ((col) & 0xff) / 255 - (10 * i);
	//col = rgb_con(lst);
	return (col + (10 * i));
}