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

void	ft_bresenham(int x0, int y0, int x1, int y1, t_setup *setup)
{
	int		deltax;
	int		deltay;
	int		delta;
	int		y;

	if (x0 == x1)
		ft_vertical_line(x0, y0, y1, setup);
	if (x0 > x1)
		ft_swap(&x0, &x1);
	if (y0 > y1)
		ft_swap(&y0, &y1);
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

void	ft_newbresenham(int x0, int y0, int x1, int y1, t_setup *setup)
{
	int		steep;
	int		dx;
	int		dy;
	int		err;
	int		derr;
	int		y;

	steep = 0;
	if (ABS(x0 - x1) < ABS(y0 - y1))
	{
		ft_swap(&x0, &y0);
		ft_swap(&x1, &y1);
		steep = 1;
	}
	if (x0 > x1)
	{
		ft_swap(&x0, &x1);
		ft_swap(&y0, &y1);
	}
	dx = x1 - x0;
	dy = y1 - y0;
	derr = ABS(dy) * 2;
	err = 0;
	y = y0;
	while (x0 < x1)
	{
		if (steep)
			check_and_draw(setup, hpt(y + HEIGHT / 2, x0 + WIDTH / 2, 0, 0));
		else
			check_and_draw(setup, hpt(x0 + WIDTH / 2, y + HEIGHT / 2, 0, 0));
		err += derr;
		if (err > dx)
		{
			y += (y1 > y0 ? 1 : -1);
			err -= dx * 2;
		}
		x0++;
	}
}
