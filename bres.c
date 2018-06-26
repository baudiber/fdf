
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:25:28 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/26 15:26:16 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_vertical_line(int x, int y0, int y1, t_setup *setup)
{
	while (y0 < y1)
	{
		setup->data[WIDTH * y0 + x] = 0xFFFFFF;
		y0++;
	}	
}

void	ft_bresenham(t_hpt p1, t_hpt p2, int **img)
{
	int dx,dy,i,xinc,yinc,cumul,x,y;

	x = p1.x;
	y = p1.y;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = ABS(dx);
	dy = ABS(dy);
	check_and_draw(img, hpt(x + WIDTH / 2, y + HEIGHT / 2, 0, 0), p2.color);
	i = 1;
	if (dx > dy) 
	{
		cumul = dx / 2;
		while (i <= dx) 
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dx) 
			{
				cumul -= dx;
				y += yinc; 
			}
			check_and_draw(img, hpt(x + WIDTH / 2, y + HEIGHT / 2, 0, 0), p2.color);
			i++;
		} 
	}
	else 
	{
		cumul = dy / 2;
		while (i <= dy) 
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy) 
			{
				cumul -= dy;
				x += xinc; 
			}
			check_and_draw(img, hpt(x + WIDTH / 2, y + HEIGHT / 2, 0, 0), p2.color);
			i++;
		} 
	}
}
