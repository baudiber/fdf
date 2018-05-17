/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:41:14 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/17 21:04:09 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_window(char *str, int width, int height, t_setup *setup)
{
	setup->width = width;
	setup->height = height;
	setup->win_ptr = mlx_new_window(setup->mlx_ptr, width, height, str);
}

void	env_points(t_setup *setup)
{
	setup->lastrow = setup->ynb * setup->linelen - setup->linelen; 	
	setup->q0.w = 30;
	setup->q0.vect.x = 1;
	setup->q0.vect.y = 0;
	setup->q0.vect.z = 0;
}
