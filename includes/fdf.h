/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:54:39 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/25 16:05:14 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# define H 1200
# define W 1200
# define RAD(x) ((x) * M_PI / 360)
# define DEG(y) ((y) * 360 / M_PI)
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
	int				col;
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
	double			step;
	double			error;
}					t_d;

typedef struct		s_v
{
	int				max_x;
	int				max_y;
	int				rand;
	int				dx;
	int				dy;
	void			*mlx;
	void			*win;
	double			zoom;
	double			alpha;
	double			beta;
	double			gamma;
	double			dist_x;
	double			dist_y;
	double			mult_z;
	t_lst			*el;
}					t_v;

t_lst				*new_elem(char *arr, int i, int j);

t_lst				*map_read(t_lst *list, int fd, t_v *v);

t_lst				*rot(t_lst *lst, t_v *v);

void				iso(t_v *v);

void				draw(t_v *v);

void				zero_angles(t_v *v);

void				draw_grid(t_v *v, char *name);

void				line(t_lst *d0, t_lst *d1, t_v *v);

int					key_hook(int key, t_v *v);

int					rgb_con(t_lst *lst);

#endif
