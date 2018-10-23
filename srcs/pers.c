/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pers.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 17:30:29 by baudiber          #+#    #+#             */
/*   Updated: 2018/10/23 15:28:37 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** apply DEPTH perspective on the points
*/

t_hpt		apply_pers_hpt(t_hpt p, t_scene *s)
{
	if (p.z == 0.0)
		p.z = 0.001;
	p.x *= HEIGHT / (tan(s->cam.fov / 2) * p.z);
	p.y *= HEIGHT / (tan(s->cam.fov / 2) * p.z);
	return (p);
}

/*
** setup the matrix that deals with rotations
*/

void		get_scene_mat(t_scene *scene)
{
	scene->mat = scale_mat(scene->scale);
	scene->mat = mult_4x4mat(rot_mat_y(scene->rot.y), scene->mat);
	scene->mat = mult_4x4mat(rot_mat_x(scene->rot.x), scene->mat);
	scene->mat = mult_4x4mat(rot_mat_z(scene->rot.z), scene->mat);
	scene->mat = mult_4x4mat(rot_mat_pos(scene->pos), scene->mat);
}

/*
** creates a basic lookat camera matrix
*/

t_mat4x4	look_at_mat(t_scene *s)
{
	t_hpt		f;
	t_hpt		r;
	t_hpt		u;
	t_mat4x4	mat;

	f = normalize_vect(sub_vects(s->cam.from, s->cam.to));
	r = normalize_vect(cross_product(f, hpt(0, -1, 0, 1)));
	u = normalize_vect(cross_product(r, f));
	mat.m[0][0] = r.x;
	mat.m[0][1] = r.y;
	mat.m[0][2] = r.z;
	mat.m[1][0] = u.x;
	mat.m[1][1] = u.y;
	mat.m[1][2] = u.z;
	mat.m[2][0] = -f.x;
	mat.m[2][1] = -f.y;
	mat.m[2][2] = -f.z;
	return (mat);
}

/*
**  rotate that lookat matrix by the position of the camera
*/

t_mat4x4	get_cam_mat(t_scene *s)
{
	t_mat4x4	mat;

	mat = mult_4x4mat(look_at_mat(s), rot_mat_pos(conjugate(s->cam.from)));
	return (mat);
}
