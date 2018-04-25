/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:54:58 by baudiber          #+#    #+#             */
/*   Updated: 2018/04/25 19:44:16 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

double	ipart(int x)
{
	return (floor(x));
}

double	ft_round(int x)
{
	return (ipart(x + 0.5));
}

float	fpart(int x)
{
	return (x - floor(x)); 
}

float	rfpart(int x)
{
	return (1 - fpart(x));
}

void	ft_wu(int x0, int y0, int x1, int y1)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		steep;
	int		dx;
	int		dy;
	float	grad;
	float		xend;
	float		yend;
	float		xgap;
	float		xpxl1;
	float		ypxl1;
	float		xpxl2;
	float		ypxl2;
	float		intery;
	int			x;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "~  <baudiber>'s fdf  ~");
	steep = (y1 - y0) > (x1 - x0);

	if (steep)
	{
		ft_swap(&x0, &y0);	
		ft_swap(&x1, &y1);	
	}
	if (x0 > x1)
	{
		ft_swap(&x0, &x1);	
		ft_swap(&y0, &y1);	
	}
	dx = x1 - x0;
	dy = y1 - y0;
	grad = dy / dx;
	if (dx == 0)
		grad = 1;
	xend = ft_round(x0);
	yend = y0 + grad * (xend - x0);
	xgap = rfpart(x0 + 0.5);
	xpxl1 = xend;
	ypxl1 = ipart(yend);
	if (steep)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, ypxl1, xpxl1, 0xFFFFFF + (rfpart(yend) * xgap) * 0x01000000);
		mlx_pixel_put(mlx_ptr, win_ptr, ypxl1 + 1, xpxl1, 0xFFFFFF + (fpart(yend) * xgap) * 0x01000000);
	}
	else
	{
		mlx_pixel_put(mlx_ptr, win_ptr, ypxl1, xpxl1, 0xFFFFFF + (rfpart(yend) * xgap) * 0x01000000);
		mlx_pixel_put(mlx_ptr, win_ptr, ypxl1, xpxl1 + 1, 0xFFFFFF + (fpart(yend) * xgap) * 0x01000000);
	}
	intery = yend + grad;
	xend = ft_round(x1);
	yend = y1 + grad * (xend - x1);
	xgap = fpart(x1 + 0.5);
	xpxl2 = xend;
	ypxl2 = ipart(yend);
	if (steep)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, ypxl2, xpxl2, 0xFFFFFF + (rfpart(yend) * xgap) * 0x01000000);
		mlx_pixel_put(mlx_ptr, win_ptr, ypxl2 + 1, xpxl2, 0xFFFFFF + (fpart(yend) * xgap) * 0x01000000);
	}
	else
	{
		mlx_pixel_put(mlx_ptr, win_ptr, ypxl2, xpxl2, 0xFFFFFF + (rfpart(yend) * xgap) * 0x01000000);
		mlx_pixel_put(mlx_ptr, win_ptr, ypxl2, xpxl2 + 1, 0xFFFFFF + (fpart(yend) * xgap) * 0x01000000);
	}
	x = xpxl1 + 1;
	if (steep)
	{
		while (x < xpxl2 - 1)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, ipart(intery), x, 0xFFFFFF + rfpart(intery) * 0x01000000);
			mlx_pixel_put(mlx_ptr, win_ptr, ipart(intery) + 1, x, 0xFFFFFF + fpart(intery) * 0x01000000);
			intery += grad;
			x++;
		}
	}
	else
	{
		while (x < xpxl2 - 1)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, ipart(intery),  0xFFFFFF + rfpart(intery) * 0x01000000);
			mlx_pixel_put(mlx_ptr, win_ptr,  x, ipart(intery) + 1, 0xFFFFFF + fpart(intery) * 0x01000000);
			intery += grad;
			x++;
		}
	}
	mlx_loop(mlx_ptr);
}
