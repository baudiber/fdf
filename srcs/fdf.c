/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:18:22 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/28 02:16:41 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		quitfdf(t_setup *stp)
{
	free_all(stp);
	exit(1);
	return (0);
}

void	fdf(t_setup *stp)
{
	display_splash(stp);
	mlx_key_hook(stp->win_ptr, stp_key, stp);
	mlx_hook(stp->win_ptr, 2, (1L << 0), keys, stp);
	mlx_hook(stp->win_ptr, 17, 0L, quitfdf, stp);
	mlx_loop(stp->mlx_ptr);
}
