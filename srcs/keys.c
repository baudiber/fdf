/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:30:12 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/05 23:33:39 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	cam_pos_wasd(int key, t_setup *stp)
{
	if (key == 13)
	{
		stp->scene.cam.from.y += 10;
		stp->scene.cam.to.y += 10;
	}
	if (key == 0)
	{
		stp->scene.cam.from.x -= 10;
		stp->scene.cam.to.x -= 10;
	}
	if (key == 1)
	{
		stp->scene.cam.from.y -= 10;
		stp->scene.cam.to.y -= 10;
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
		stp->map.scale.y += 100;
		stp->map.scale.z += 100;
		stp->map.scale.x += 100;
	}
	if (key == 125 && stp->map.scale.y > 0)
	{
		stp->map.scale.y -= 100;
		stp->map.scale.z -= 100;
		stp->map.scale.x -= 100;
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

void	stp_rpbh(int key, t_setup *stp)
{
	if (key == 15)
	{
		if (stp->scene.dot == 1)
			stp->scene.dot = 0;
		else
			stp->scene.dot = 1;
	}
	if (key == 35)
	{
		if (stp->scene.pers == 0)
			stp->scene.pers = 1;
		else
			stp->scene.pers = 0;
	}
	if (key == 11)
	{
		stp->scene.rot = hpt(0, 0, 0, 1); 
		stp->scene.cam.from = hpt(0, 1000, 1000, 1);
		stp->scene.cam.to = hpt(0, 0, 0, 1);
		stp->scene.dot = 0;
		stp->scene.pers = 0;
	}
	if (key == 4)
	{
		if (stp->help == 0)
			stp->help = 1;
		else
			stp->help = 0;
	}
}

int		stp_key(int key, t_setup *stp)
{
	if (key == 49)
	{
		if (stp->splash == 0)
			stp->splash = 1;
	}
	if (key == 53)
		exit (0);
	if (stp->splash)
		stp_rpbh(key, stp);
	redraw(stp);
	//printf("%d\n", key);
	return (0);
}

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

