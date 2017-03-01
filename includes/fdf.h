/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:54:39 by dmulish           #+#    #+#             */
/*   Updated: 2017/03/01 20:18:52 by dmulish          ###   ########.fr       */
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

typedef struct		s_e
{
	int				x;
	int				y;
	int				z;
	unsigned char	R;
	unsigned char	G;
	unsigned char	B;
}					t_e;

typedef struct		s_lst
{
	t_e				*cord;
	struct s_lst	*next;
}					t_lst;

t_lst				*map_read(t_lst *list, int fd);

#endif
