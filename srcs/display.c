#include "fdf.h"

void	check_and_draw(t_setup *stp, t_hpt pt)
{
	if ((int)pt.x <= 0 || (int)pt.x > WIDTH - 2 || (int)pt.y <= 0 || (int)pt.y > HEIGHT - 2)
		return ;
	stp->data[(int)pt.y * WIDTH + (int)pt.x] = 0xFFFFFF;
}

void	draw_dot(t_setup *stp, t_hpt pt)
{
	pt.x += WIDTH / 2;
	pt.y += HEIGHT / 2;	
	check_and_draw(stp, pt);
}

void	display_dots(t_setup *stp)
{
	int		i;

	i = 0;
	while (i < stp->ptnb)
	{
		if (stp->scene.pers == 1)
			stp->map.npts[i] = apply_pers_hpt(stp->map.npts[i], &stp->scene);
		stp->map.npts[i].z = (stp->map.npts[i].z - stp->scene.cam.near) / stp->scene.cam.far;
		draw_dot(stp, stp->map.npts[i]);		
		i++;
	}
}

void	display_lines(t_setup *stp)
{
	int		i;

	i = 0;
	//while (i < stp->linelen * stp->ynb)
	while (i < stp->lastrow)
	{
		ft_bresenham(stp->map.npts[i].x, stp->map.npts[i].y, stp->map.npts[i + stp->linelen].x, stp->map.npts[i + stp->linelen].y, stp);
		i += stp->linelen;
		//printf("test %d\n", i);
	}
}
