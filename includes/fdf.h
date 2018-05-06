/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:18:24 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/06 23:50:07 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
# define _FDF_H_

# include "mlx.h"
# include "libft.h"
# include <stdio.h>

typedef struct		s_point
{
	int				x;
	int				y;
	unsigned int	color;
}					t_point;

typedef struct		s_rows
{
	char			*line;
	char			**tab;
	struct s_rows	*next;
}					t_rows;


typedef struct		s_setup
{
	struct s_point	*points;
	int				width;
	int				height;
	int				*data;
	int				bpx;
	int				s_line;
	int				ed;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				ptnb;
	int				ynb;
	int				linelen;
}					t_setup;

void				parser(char *av, t_setup *setup);
void				ft_errors(int type);
void				ft_bresenham(int x0, int y0, int x1, int y1, t_setup *setup);
void				ft_wu(int x0, int y0, int x1, int y1);

#endif
