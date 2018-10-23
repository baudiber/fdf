/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:18:22 by baudiber          #+#    #+#             */
/*   Updated: 2018/10/23 15:36:20 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		quitfdf(t_setup *stp)
{
	free_all(stp);
	exit(1);
	return (0);
}

void	reset_view(t_setup *stp)
{
	stp->map.scale = hpt(800, 800, 800, 1);
	stp->scene.rot = hpt(0, 0, 0, 1);
	stp->scene.cam.from = hpt(0, 1000, 1000, 1);
	stp->scene.cam.to = hpt(0, 0, 0, 1);
	stp->scene.dot = 0;
	stp->scene.pers = 0;
}

/*
** main mlx function with the main loop and events
*/

void	fdf(t_setup *stp)
{
	display_splash(stp);
	free_all(stp);
	parser(stp, stp->av);
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, WIDTH / 2 - 90, \
			390 / 2, 0x00FF00, "Parsing was succesful");
	init_all(stp);
	mlx_key_hook(stp->win_ptr, stp_key, stp);
	mlx_hook(stp->win_ptr, 2, (1L << 0), keys, stp);
	mlx_hook(stp->win_ptr, 17, 0L, quitfdf, stp);
	mlx_loop(stp->mlx_ptr);
}
