/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:30:12 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/31 00:02:54 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int		deal_key(int key, t_setup *stp)
{
	if (key == 126)
	{
		printf("^\n");
		stp->map.scale.y += 100;
		stp->map.scale.z += 100;
		stp->map.scale.x += 100;
		redraw(stp);
	}
	if (key == 125)
	{
		printf("v\n");
		stp->map.scale.y -= 100;
		stp->map.scale.z -= 100;
		stp->map.scale.x -= 100;
		redraw(stp);
	}
	if (key == 123)
	{
		printf("<\n");
	}
	if (key == 124)
	{
		printf(">\n");
	}
	if (key == 49)
	{
		printf("space\n");
		if (stp->splash == 0)
		{
			stp->splash = 1;
			redraw(stp);
		}
	}
	if (key == 13)
	{
		printf("W\n");
		stp->map.pos.y += 100;
//		stp->scene.cam.from.y += 100;
//		stp->scene.cam.to.y += 100;
		redraw(stp);
	}
	if (key == 1)
	{
		printf("S\n");
		stp->map.pos.y -= 100;
//		stp->scene.cam.from.y -= 100;
//		stp->scene.cam.to.y -= 100;
		redraw(stp);
	}
	if (key == 2)
	{
		printf("D\n");
		stp->map.pos.x += 100;
//		stp->scene.cam.to.x += 100;
//		stp->scene.cam.from.x += 100;
		redraw(stp);
	}
	if (key == 0)
	{
		printf("A\n");
		stp->map.pos.x -= 100;
//		stp->scene.cam.from.x -= 100;
//		stp->scene.cam.to.x -= 100;
		redraw(stp);
	}
	if (key == 15)
	{
		printf("R\n");
		if (stp->scene.dot == 1)
			stp->scene.dot = 0;
		else if (stp->scene.dot == 0)
			stp->scene.dot = 1;
		redraw(stp);
	}
	if (key == 35)
	{
		printf("P\n");
		if (stp->scene.pers == 0)
			stp->scene.pers = 1;
		else if (stp->scene.pers == 1)
			stp->scene.pers = 0;
		redraw(stp);
	}
	/*
	if (key == 4)
	{
		//display help
	}
	*/
	if (key == 53)
		exit (0);
	printf("%d\n", key);
	return (0);
}
