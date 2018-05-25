/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 23:21:41 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/23 01:40:59 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_window(char *str, t_setup *setup)
{
	setup->win_ptr = mlx_new_window(setup->mlx_ptr, WIDTH, HEIGHT, str);
}


void	cam_scene_settings(t_setup *stp)
{
	stp->scene.scale = hpt(1, 1, 1, 1); 
	stp->scene.rot = hpt(0, 0, 0, 1); 
	stp->scene.pos = hpt(0, 0, 0, 1); 
	stp->scene.cam.fov = 90;
	stp->scene.cam.from = hpt(0, 1000, 1000, 1);
	stp->scene.cam.to = hpt(0, 0, 0, 1);
	stp->scene.cam.near = 500; 
	stp->scene.cam.far = 3000; 
	stp->scene.dot = 0;
}

void	init_all(t_setup *stp)
{
	stp->mlx_ptr = mlx_init();
	create_window(stp->av, stp);
	stp->img_ptr = mlx_new_image(stp->mlx_ptr, WIDTH, HEIGHT);
	stp->data = (int *)mlx_get_data_addr(stp->img_ptr, &stp->bpx, &stp->s_line, &stp->ed);
	stp->splash = 0;
	stp->lastrow = stp->ynb * stp->linelen - stp->linelen; 	
	stp->map.pos = hpt(0, 0, 0, 1); 
	stp->map.scale = hpt(800, 800, 800, 1);
	stp->map.rot = hpt(0 , -M_PI / 4, 0, 1);
	cam_scene_settings(stp);
}