/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:54:39 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/22 18:15:29 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# define H 1200
# define W 1200
# define RAD(x) (x) * M_PI / 360
# define SWAP(a, b) { a ^= b; b ^= a; a ^= b; }
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
	int				x1;
	int				y1;
	int				z1;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_d
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				z0;
	int				z1;
	int				dx;
	int				dy;
	int				s;
	int				step;
	int				error;
}					t_d;

typedef struct		s_v
{
	int				max_x;
	int				max_y;
	int				dist_x;
	int				dist_y;
	void			*mlx;
	void			*win;
	t_lst			*el;
}					t_v;

t_lst				*new_elem(char *arr, int i, int j);

t_lst				*map_read(t_lst *list, int fd, t_v *v);

void				draw(t_v *v);

void				draw_grid(t_v *v, char *name);

void				line(t_lst *d0, t_lst *d1, t_v *v);

#endif
