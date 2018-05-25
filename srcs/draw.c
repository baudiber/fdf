#include "fdf.h"

void	reset_img(t_setup *stp)
{
	int		i;

	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		stp->data[i] = 0;
		i++;
	}
}

void	get_scene_mat(t_scene *scene)
{
	scene->mat = scale_mat(scene->scale);
	scene->mat = mult_4x4mat(rot_mat_y(scene->rot.y), scene->mat);
	scene->mat = mult_4x4mat(rot_mat_x(scene->rot.x), scene->mat);
	scene->mat = mult_4x4mat(rot_mat_z(scene->rot.z), scene->mat);
	scene->mat = mult_4x4mat(rot_mat_pos(scene->pos), scene->mat);
}

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

void	get_cam_mat(t_scene *s)
{
	t_mat4x4	mat;

	mat = mult_4x4mat(look_at_mat(s), rot_mat_pos(conjugate(s->cam.from)));
}

void	get_map_mat(t_mat4x4 smat, t_map *map)
{
	map->mat = scale_mat(map->scale);	
	map->mat = mult_4x4mat(rot_mat_y(map->rot.y), map->mat);
	map->mat = mult_4x4mat(rot_mat_x(map->rot.x), map->mat);
	map->mat = mult_4x4mat(rot_mat_z(map->rot.z), map->mat);
	map->mat = mult_4x4mat(rot_mat_pos(map->pos), map->mat);
	map->mat = mult_4x4mat(smat, map->mat);
}

void	draw(t_setup *stp)
{
	get_scene_mat(&stp->scene);
	get_cam_mat(&stp->scene);
	get_map_mat(stp->scene.mat, &stp->map);
	//vect4 * matrix4x4
	//print points
}

void	redraw(t_setup *stp)
{
	reset_img(stp);
	draw(stp);

	mlx_put_image_to_window(stp->data, stp->win_ptr, stp->img_ptr, 0, 0);
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, 850, 740, 0xF0F0F0, "Press h for help");
}
