/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:41:14 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/08 00:28:56 by baudiber         ###   ########.fr       */
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
	setup->init.a = cos(20 / 2);
	//setup->init.vect.x = 
	//setup->init.vect.y = 
	//setup->init.vect.z = 
}
