/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:54:39 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/03 21:05:44 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

typedef struct		s_lst
{
	int				x;
	int				y;
	int				z;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_v
{
	int				max_x;
	int				x;
	int				y;
	void			*mlx;
	void			*win;
}					t_v;

t_lst				*map_read(t_lst *list, int fd, t_v *v);

void				draw_grid(t_lst *map, char *name);

#endif
