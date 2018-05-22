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

void	init_all(t_setup *stp)
{
	stp->mlx_ptr = mlx_init();
	create_window(stp->av, stp);
	stp->img_ptr = mlx_new_image(stp->mlx_ptr, WIDTH, HEIGHT);
	stp->data = (int *)mlx_get_data_addr(stp->img_ptr, &stp->bpx, &stp->s_line, &stp->ed);
	stp->splash = 1;
	stp->lastrow = stp->ynb * stp->linelen - stp->linelen; 	
}
