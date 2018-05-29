/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:30:12 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/23 01:43:35 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int		deal_key(int key, t_setup *stp)
{
	if (key == 126)
	{
		printf("^\n");
		stp->map.pos.x += 100;
		redraw(stp);
	}
	if (key == 125)
	{
		printf("v\n");
		stp->map.pos.x -= 100;
		redraw(stp);
	}
	if (key == 123)
	{
		printf("<\n");
		stp->map.pos.y -= 100;
		redraw(stp);
	}
	if (key == 124)
	{
		printf(">\n");
		stp->map.pos.y += 100;
		redraw(stp);
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
		if (stp->scene.pers == 0)
			stp->scene.pers = 1;
		else if (stp->scene.pers == 1)
			stp->scene.pers = 0;
		redraw(stp);
	}
	if (key == 1)
	{
		printf("S\n");
		stp->map.scale.y -= 100;
		stp->map.scale.z -= 100;
		stp->map.scale.x -= 100;
		redraw(stp);
	}
	if (key == 2)
	{
		printf("D\n");
		if (stp->scene.dot == 1)
			stp->scene.dot = 0;
		else if (stp->scene.dot == 0)
			stp->scene.dot = 1;
		redraw(stp);
	}
	//printf("%d\n", key);
	/*
	if (key == 0)
		//a
	if (key == 4)
		//display help
	*/
	if (key == 53)
		exit (0);
	return (0);
}
