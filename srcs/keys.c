/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 17:31:08 by baudiber          #+#    #+#             */
/*   Updated: 2018/10/23 17:37:07 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cam_pos_wasd(int key, t_setup *stp)
{
	if (key == 13)
	{
		stp->scene.cam.from.z -= 10;
		stp->scene.cam.to.z -= 10;
	}
	if (key == 0)
	{
		stp->scene.cam.from.x -= 10;
		stp->scene.cam.to.x -= 10;
	}
	if (key == 1)
	{
		stp->scene.cam.from.z += 10;
		stp->scene.cam.to.z += 10;
	}
	if (key == 2)
	{
		stp->scene.cam.to.x += 10;
		stp->scene.cam.from.x += 10;
	}
	redraw(stp);
}

void	scene_rot_ikjl(int key, t_setup *stp)
{
	if (key == 34)
		stp->scene.rot.x += 0.1;
	if (key == 40)
		stp->scene.rot.x -= 0.1;
	if (key == 38)
		stp->scene.rot.y -= 0.1;
	if (key == 37)
		stp->scene.rot.y += 0.1;
	redraw(stp);
}

void	arrow_udlr(int key, t_setup *stp)
{
	if (key == 126)
	{
		stp->map.scale.y *= 1.2;
		stp->map.scale.z *= 1.2;
		stp->map.scale.x *= 1.2;
	}
	if (key == 125 && stp->map.scale.y > 0)
	{
		stp->map.scale.y /= 1.2;
		stp->map.scale.z /= 1.2;
		stp->map.scale.x /= 1.2;
	}
	if (key == 123)
	{
		stp->map.scale.y -= 100;
	}
	if (key == 124)
	{
		stp->map.scale.y += 100;
	}
	redraw(stp);
}

/*
** if splash is true splash is actually off
** main key even function that redirects others
*/

int		keys(int key, t_setup *stp)
{
	if (stp->splash)
	{
		if (key == 13 || key == 1 || key == 2 || key == 0)
			cam_pos_wasd(key, stp);
		if (key == 34 || key == 40 || key == 38 || key == 37)
			if (stp->scene.pers == 1)
				scene_rot_ikjl(key, stp);
		if (key == 123 || key == 124 || key == 125 || key == 126)
			arrow_udlr(key, stp);
	}
	return (0);
}
