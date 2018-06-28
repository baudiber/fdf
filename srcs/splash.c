/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:42:03 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/28 02:17:41 by baudiber         ###   ########.fr       */
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

void	init_splash_map(t_setup *stp)
{
	parser(stp, "test_maps/splash.fdf");
	init_all(stp);
	stp->scene.pers = 1;
	stp->map.scale = hpt(2400, 3800, 2400, 1);
	stp->scene.rot.y = 5.499988;	
	stp->scene.rot.x = 3.79999;	
	stp->scene.cam.to.x = 0;	
	stp->scene.cam.to.z = 30.00;
 	stp->scene.cam.from.z = 1030.00;	
	stp->scene.cam.from.x = 0;	
	redraw(stp);
}

void	display_splash(t_setup *stp)
{
	init_splash_map(stp);
	splash_art(stp);
	mlx_put_image_to_window(stp->data, stp->win_ptr, stp->img_ptr, 0, 0);
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, WIDTH / 2 - 50, \
			HEIGHT / 2  / 2 - 20, 0xFFFFFF, "Wireframe v0.1");
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, WIDTH / 2 - 90, \
			390 / 2, 0x00FF00, "Parsing was succesful");
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, WIDTH / 2 - 85, \
			450 / 2, 0xFFFFFF, "Press Space to start");
}
