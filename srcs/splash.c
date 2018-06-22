/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:42:03 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/22 12:58:46 by baudiber         ###   ########.fr       */
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
	stp->map.scale = hpt(3500, 3500, 3500, 1);
	stp->scene.rot.y = 2.99999;	
	stp->scene.rot.x = 0.80000;	
	stp->scene.cam.to.x = 20.00;	
	stp->scene.cam.from.x = 20.00;	
	stp->scene.cam.to.z = -110.00;
 	stp->scene.cam.from.z = 890.00;	
}

void	display_splash(t_setup *stp)
{
	splash_art(stp);
	init_splash_map(stp);
	mlx_put_image_to_window(stp->data, stp->win_ptr, stp->img_ptr, 0, 0);
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, WIDTH / 2 - 50, \
			HEIGHT / 2 - 20, 0xFFFFFF, "Wireframe v0.1");
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, WIDTH / 2 - 90, \
			390, 0x00FF00, "Parsing was succesful");
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, WIDTH / 2 - 85, \
			420, 0xFFFFFF, "Press Space to start");
}
