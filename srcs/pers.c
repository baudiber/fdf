#include "fdf.h"

t_hpt	apply_pers_hpt(t_hpt p, t_scene *s)
{
	if (p.z == 0.0)
		p.z = 0.001;
	p.x *= HEIGHT / (tan(s->cam.fov / 2) * p.z);
	p.y *= HEIGHT / (tan(s->cam.fov / 2) * p.z);
	return (p);
}
