/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:18:24 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/21 00:46:19 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
# define _FDF_H_
# define WIDTH 	1024
# define HEIGHT 724
# define ABS(x) ((x > 0) ? x : -x)

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>

typedef struct s_hpt	t_hpt;
typedef struct s_rows	t_rows;
typedef struct s_map	t_map;
typedef struct s_setup	t_setup;
typedef struct s_mat4x4 t_mat4x4;
typedef struct s_cam	t_cam;
typedef struct s_scene	t_scene;

struct				s_hpt
{
	float			x;
	float			y;
	float			z;
	float			w;
	unsigned int	color;
};

struct				s_mat4x4
{
	float			m[4][4];
};

struct				s_rows
{
	char			*line;
	char			**tab;
	t_rows			*next;
};

struct				s_cam
{
	float			fov;
	float			near;
	float			far;
	t_hpt			from;
	t_hpt			to;
	t_mat4x4		mat;
};

struct				s_scene
{
	t_cam			cam;
	t_hpt			pos;
	t_hpt			scale;
	t_hpt			rot;
	int				dot;
	int				pers;
	t_mat4x4		mat;
};

struct				s_map
{
	t_mat4x4		mat;
	int				highest;
	t_hpt			*pts;
	t_hpt			*tpts;
	t_hpt			*npts;
	t_hpt			scale;
	t_hpt			rot;
	t_hpt			pos;
};

struct				s_setup
{
	t_map			map;
	t_scene			scene;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				ac;
	char			*av;
	int				*data;
	int				help;
	int				bpx;
	int				s_line;
	int				ed;
	int				ptnb;
	int				ynb;
	int				linelen;
	int				lastrow;
	int				splash;
	double			mat[3][3];
};

void				parser(t_setup *setup);
void				ft_errors(int type);
void				init_all(t_setup *stp);
void				fdf(t_setup *stp);
void				create_window(char *str, t_setup *setup);
int					stp_key(int key, t_setup *stp);
void				display_splash(t_setup *setup);
t_hpt				normalize_vect(t_hpt v);
t_hpt				sub_vects(t_hpt a, t_hpt b);
t_hpt				cross_product(t_hpt v0, t_hpt v1);
void				get_matrix(t_setup *stp);
void				redraw(t_setup *stp);
t_hpt				conjugate(t_hpt v);
t_mat4x4			mult_4x4mat(t_mat4x4 m1, t_mat4x4 m2);
t_mat4x4			scale_mat(t_hpt scale);
t_mat4x4			id_mat(void);
t_hpt				hpt(float x, float y, float z, float w);
t_mat4x4			rot_mat_x(float x);
t_mat4x4			rot_mat_y(float y);
t_mat4x4			rot_mat_z(float z);
t_mat4x4			rot_mat_pos(t_hpt vec);
t_hpt				mult_4x4mat_hpt(t_mat4x4 mat, t_hpt p);
void				display_dots(t_setup *stp);
void				display_lines(t_setup *stp);
t_hpt				apply_pers_hpt(t_hpt p, t_scene *s);
void				check_and_draw(int **img, t_hpt pt, unsigned int color);
void				ft_bresenham(t_hpt p1, t_hpt p2, int **img);
void				display_help(t_setup *stp);
int					keys(int key, t_setup *stp);
void				cam_scene_settings(t_setup *stp);
t_hpt				clipping(t_hpt p1);

#endif
