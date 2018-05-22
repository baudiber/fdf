/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:18:24 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/20 18:08:00 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
# define _FDF_H_

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>

typedef struct		s_vect
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef struct		s_point
{
	struct s_vect	vect;
	unsigned int	color;
}					t_point;

typedef struct		s_quat
{
	double			w;
	struct s_vect	vect;
}					t_quat;

typedef struct		s_rows
{
	char			*line;
	char			**tab;
	struct s_rows	*next;
}					t_rows;

typedef struct		s_setup
{
	struct s_point	*pts;
	struct s_point	*npts;
	struct s_quat	q0;
	struct s_quat	q1;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				ac;
	int				*data;
	int				bpx;
	int				s_line;
	int				ed;
	int				width;
	int				height;
	int				ptnb;
	int				ynb;
	int				linelen;
	int				lastrow;
	double			mat[3][3];
}					t_setup;

void				parser(char *av, t_setup *setup);
void				ft_errors(int type);
void				ft_bresenham(int x0, int y0, int x1, int y1, t_setup *setup);
void				ft_wu(int x0, int y0, int x1, int y1);
void				create_window(char *str, int width, int height, t_setup *setup);
void				env_points(t_setup *setup);
void				display(t_setup *setup);
int					deal_key(int key, t_setup *stp);
void				display_splash(t_setup *setup);
t_quat				quaternion_multiplicator(t_quat q0, t_quat q1);
t_vect				normalize_vect(t_vect v);
t_vect				sub_vects(t_vect a, t_vect b);
t_vect				cross_product(t_vect v0, t_vect v1);
void				get_matrix(t_quat q, t_setup *stp);
t_quat				conjugate(t_quat q);
void				redraw(t_setup *stp);

#endif
