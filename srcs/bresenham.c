/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:25:28 by baudiber          #+#    #+#             */
/*   Updated: 2018/04/25 18:47:02 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham(int x0, int y0, int x1, int y1)
{
	int		deltax = x1 - x0;
	int		deltay = y1 - y0;
	int		delta = 2 * deltay - deltax;
	int		y = y0;
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "~  <baudiber>'s fdf  ~");
	while (x0 < x1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x0, y, 0xFFFFFF);
		if (delta > 0)
		{
			y++;
			delta = delta - 2 * deltax;
		}
		delta = delta + 2 * deltay;
		x0++;
	}
	mlx_loop(mlx_ptr);
}
