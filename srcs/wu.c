/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:54:58 by baudiber          #+#    #+#             */
/*   Updated: 2018/04/28 18:19:23 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

#define ft_ipart(X) ((int)(X))
#define ft_round(X) ((int)(((double)(X))+ 0.5))
#define ft_fpart(X) (((double)(X)) - (double)ft_ipart(X))
#define ft_rfpart(X) (1.0 - ft_fpart(X))
#define W 0x00FFFFFF
#define TP 0xFF000000

void	ft_wu(int x0, int y0, int x1, int y1)
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			steep;
	double		dx;
	double		dy;
	double		grad;
	double		xend;
	double		yend;
	double		xgap;
	int			xpxl1;
	int			ypxl1;
	int			xpxl2;
	int			ypxl2;
	double		intery;
	int			x;
	unsigned int	rfcolor;
	unsigned int	fcolor;

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
	xgap = ft_rfpart(x0 + 0.5);
	xpxl1 = xend;
	ypxl1 = ft_ipart(yend);
	if (steep)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, ypxl1, xpxl1, W + (ft_rfpart(yend) * xgap) * TP);
		mlx_pixel_put(mlx_ptr, win_ptr, ypxl1 + 1, xpxl1, W + (ft_fpart(yend) * xgap) * TP);
	}
	else
	{
		mlx_pixel_put(mlx_ptr, win_ptr, ypxl1, xpxl1, W + (ft_rfpart(yend) * xgap) * TP);
		mlx_pixel_put(mlx_ptr, win_ptr, ypxl1, xpxl1 + 1, W + (ft_fpart(yend) * xgap) * TP);
	}
	intery = yend + grad;
	xend = ft_round(x1);
	yend = y1 + grad * (xend - x1);
	xgap = ft_fpart(x1 + 0.5);
	xpxl2 = xend;
	ypxl2 = ft_ipart(yend);
	if (steep)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, ypxl2, xpxl2, W + ((ft_rfpart(yend) * xgap) * TP));
		mlx_pixel_put(mlx_ptr, win_ptr, ypxl2 + 1, xpxl2, W + ((ft_fpart(yend) * xgap) * TP));
	}
	else
	{
		mlx_pixel_put(mlx_ptr, win_ptr, ypxl2, xpxl2, W + ((ft_rfpart(yend) * xgap) * TP));
		mlx_pixel_put(mlx_ptr, win_ptr, ypxl2, xpxl2 + 1, W + ((ft_fpart(yend) * xgap) * TP));
	}
	x = xpxl1 + 1;
// 1.00  = 0x00000000
// 0.75  = 0x08000000 
// 0.50  = 0x10000000
// 0.25  = 0x18000000
	if (steep)
	{
		while (x <= xpxl2 - 1)
		{
			printf("%f\n", ft_rfpart(intery));
			printf("%f\n", ft_fpart(intery));
			mlx_pixel_put(mlx_ptr, win_ptr, (int)intery, x, W + ft_rfpart(intery));
			mlx_pixel_put(mlx_ptr, win_ptr, (int)intery + 1, x, W + ft_fpart(intery));
			intery += grad;
			x++;
		}
	}
	else
	{
		while (x <= xpxl2 - 1)
		{
			if (ft_rfpart(intery) == 1)
			if (ft_fpart(intery) == 0.25)

			rfcolor = 0x01000000 * ((32 * (ft_rfpart(intery) * 100)) / 100);
			//fcolor = 0x01000000 * ((32 * (ft_fpart(intery) * 100)) / 100);
			fcolor = 0x01000000 * ((32 * (ft_fpart(intery) * 100)) / 100);

			//printf("%u    %f\n", (unsigned int)((32 * (ft_rfpart(intery) * 100)) / 100), ft_rfpart(intery));
			printf("%s\n", ft_utoa_base(fcolor, 16));
			printf("%s\n", ft_utoa_base(rfcolor, 16));
		//	printf("%u\n", rfcolor);
			//printf("%u\n", fcolor);
			//printf("%f\n", ft_rfpart(intery) * 100);
			//printf("%f\n", ft_fpart(intery) * 100);
			
			mlx_pixel_put(mlx_ptr, win_ptr, x, (int)intery,  W + rfcolor);
			mlx_pixel_put(mlx_ptr, win_ptr,  x, (int)intery + 1, W + fcolor);
			intery += grad;
			x++;
		}
	}
	mlx_loop(mlx_ptr);
}
