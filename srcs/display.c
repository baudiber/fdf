/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:29:44 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/31 17:37:51 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		x;
	int		y;

	y = 0;
	while (y < stp->ynb)
	{
		x = y * stp->linelen;
		while (x < (y + 1) * stp->linelen - 1)
		{
			ft_bresenham(stp->map.npts[x].x, stp->map.npts[x].y, stp->map.npts[x + 1].x, stp->map.npts[x + 1].y, stp);
			//ft_bresenham(stp->map.npts[x].x, stp->map.npts[x].y, stp->map.npts[x + stp->linelen].x, stp->map.npts[x + stp->linelen].y, stp);
			x++;
		}
		y++;
	}
}
