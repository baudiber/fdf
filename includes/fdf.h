/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:18:24 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/23 01:40:31 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
# define _FDF_H_
# define WIDTH 	1024
# define HEIGHT 724
# define GAP	30

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>

typedef struct		s_hpt
{
	float			x;
	float			y;
	float			z;
	float			w;
	unsigned int	color;
}					t_hpt;

typedef struct		s_rows
{
	char			*line;
	char			**tab;
	struct s_rows	*next;
}					t_rows;

typedef	struct		s_map
{
	struct s_hpt	*pts;
	struct s_hpt	*npts;
}					t_map;

typedef struct		s_setup
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				ac;
	char			*av;
	int				*data;
	int				bpx;
	int				s_line;
	int				ed;
	int				ptnb;
	int				ynb;
	int				linelen;
	int				lastrow;
	int				splash;
	double			mat[3][3];
}					t_setup;

void				parser(t_setup *setup, t_map *map);
void				ft_errors(int type);
void				init_all(t_setup *stp);
void				ft_bresenham(int x0, int y0, int x1, int y1, t_setup *setup);
void				create_window(char *str, t_setup *setup);
void				display(t_setup *setup);
int					deal_key(int key, t_setup *stp);
void				display_splash(t_setup *setup);
t_hpt				normalize_vect(t_hpt v);
t_hpt				sub_vects(t_hpt a, t_hpt b);
t_hpt				cross_product(t_hpt v0, t_hpt v1);
void				get_matrix(t_setup *stp);
void				redraw(t_setup *stp);

#endif
