/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:42:03 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/23 01:51:49 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	splash_art(t_setup *stp)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0xFFFFFFFF;
	while (i < WIDTH)
	{
		stp->data[WIDTH * HEIGHT / 2 + i] = j;
		if (i < WIDTH / 2 && j > 0x00FFFFFF)
			j -= 0x01000000;
		if (i >= WIDTH - (WIDTH * 25 / 100) && j < 0xFFFFFFFF)
			j += 0x01000000;
		i++;
	}
}

void	fdf_art(int **img)
{
	ft_bresenham(hpt(50, 50, 0, 0), hpt(70, 50, 0, 0), img);	
}

void	display_splash(t_setup *stp)
{
	splash_art(stp);
	fdf_art(&stp->data);
	mlx_put_image_to_window(stp->data, stp->win_ptr, stp->img_ptr, 0, 0);
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, WIDTH / 2 - 50, \
			HEIGHT / 2 - 20, 0xFFFFFF, "Wireframe v0.1");
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, WIDTH / 2 - 90, \
			390, 0x00FF00, "Parsing was succesful");
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, WIDTH / 2 - 85, \
			420, 0xFFFFFF, "Press Space to start");
}
