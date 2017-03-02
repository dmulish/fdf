/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:54:39 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/02 20:56:19 by dmulish          ###   ########.fr       */
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
# include "mlx.h"

typedef struct		s_lst
{
	int				x;
	int				y;
	int				z;
	unsigned char	R;
	unsigned char	G;
	unsigned char	B;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_v
{
	int				max_x;
}					t_v;

t_lst				*map_read(t_lst *list, int fd, t_v *v);

#endif
