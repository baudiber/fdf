/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 00:00:24 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/29 00:01:38 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		reset_view(stp);
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
	{
		free_all(stp);
		exit(0);
	}
	if (stp->splash)
	{
		stp_rpbh(key, stp);
		if (key == 8)
		{
			if (stp->clip == 0)
				stp->clip = 1;
			else
				stp->clip = 0;
		}
		redraw(stp);
	}
	return (0);
}
