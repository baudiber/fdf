/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:25:28 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/31 17:41:29 by baudiber         ###   ########.fr       */
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

/*
void	ft_bresenham(int xi, int yi, int xf, int yf, t_setup *setup)
{
	int dx,dy,i,xinc,yinc,cumul,x,y;
	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	xinc = ( dx > 0) ? 1 : -1;
	yinc = ( dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	check_and_draw(setup, hpt(x + WIDTH / 2, y + HEIGHT / 2, 0, 0));
	if ( dx > dy) 
	{
		cumul = dx / 2;
		for ( i = 1; i <= dx; i++) 
		{
			x += xinc;
			cumul += dy;
			if ( cumul >= dx) 
			{
				cumul -= dx;
				y += yinc; 
			}
			check_and_draw(setup, hpt(x + WIDTH / 2, y + HEIGHT / 2, 0, 0));
		} 
	}
	else 
	{
		cumul = dy / 2;
		for (i = 1; i <= dy; i++) 
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy) 
			{
				cumul -= dy;
				x += xinc; 
			}
			check_and_draw(setup, hpt(x + WIDTH / 2, y + HEIGHT / 2, 0, 0));
		} 
	}
}
*/

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
/*
   void	ft_bresenham(int x0, int y0, int x1, int y1, t_setup *setup)
   {
   int		deltax;
   int		deltay;
   int		delta;
   int		y;

//	if (x0 == x1)
//		ft_vertical_line(x0, y0, y1, setup);
//	if (x0 > x1)
//		ft_swap(&x0, &x1);
//	if (y0 > y1)
//		ft_swap(&y0, &y1);
y = y0;
deltax = x1 - x0;
deltay = y1 - y0;
delta = 2 * deltay - deltax;
while (x0 < x1)
{
check_and_draw(setup, hpt(x0 + WIDTH / 2, y + HEIGHT / 2, 0, 0));
//setup->data[WIDTH * y + x0] = 0xFFFFFF;
if (delta > 0)
{
y++;
delta = delta - 2 * deltax;
}
delta = delta + 2 * deltay;
x0++;
}
}
 */
