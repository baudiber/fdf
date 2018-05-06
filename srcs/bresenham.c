/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:25:28 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/06 23:19:12 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham(int x0, int y0, int x1, int y1, t_setup *setup)
{
	int		deltax = x1 - x0;
	int		deltay = y1 - y0;
	int		delta = 2 * deltay - deltax;
	int		y = y0;

	while (x0 < x1)
	{
		setup->data[setup->width * y + x0] = 0xFFFFFF;
		//mlx_pixel_put(setup->mlx_ptr, setup->win_ptr, x0, y, 0xFFFFFF);
		if (delta > 0)
		{
			y++;
			delta = delta - 2 * deltax;
		}
		delta = delta + 2 * deltay;
		x0++;
	}
}
