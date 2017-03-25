/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:34:07 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/25 17:26:48 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_lst	*new_elem(char *arr, int i, int j)
{
	char	*col;
	t_lst	*el;

	if ((el = (t_lst*)malloc(sizeof(t_lst))) == NULL)
		return (0);
	el->x = i + 1;
	el->y = j + 1;
	el->z = ft_atoi(arr);
	el->x1 = 0;
	el->y1 = 0;
	el->z1 = 0;
	el->r = '\0';
	el->g = '\0';
	el->b = '\0';
	if ((col = ft_strchr(arr, 'x')))
		el->col = ft_atoi_base(col + 1, 16);
	else
		el->col = 0xffffff;
	el->next = NULL;
	return (el);
}
