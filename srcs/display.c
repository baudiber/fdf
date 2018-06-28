/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:29:44 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/28 00:57:27 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_and_draw(int **img, t_hpt pt, unsigned int color)
{
	if ((int)pt.x <= 0 || (int)pt.x > WIDTH - 2 || (int)pt.y <= 0 || \
			(int)pt.y > HEIGHT - 2)
		return ;
	(*img)[(int)pt.y * WIDTH + (int)pt.x] = color;
}

void	draw_dot(int **img, t_hpt pt)
{
	pt.x += WIDTH / 2;
	pt.y += HEIGHT / 2;	
	check_and_draw(img, pt, pt.color);
}

int		check_pts(t_hpt pt)
{
	pt.x += WIDTH / 2;
	pt.y += HEIGHT / 2;
	if ((int)pt.x <= 0 || (int)pt.x > WIDTH - 2 || (int)pt.y <= 0 || \
			(int)pt.y > HEIGHT - 2)
		return (1);
	return (0);	
}


void	display_lines(t_setup *stp)
{
	int		x;
	int		y;
	y = 0;
	while (y < stp->ynb)
	{
		x = y * stp->linelen;
		while (x < (y + 1) * stp->linelen)
		{
			if (x < (y + 1) * stp->linelen - 1)
			{
				if (stp->clip)
				{
					if (!check_pts(stp->map.npts[x]) && !check_pts(stp->map.npts[x + 1]))
						ft_bresenham(stp->map.npts[x], stp->map.npts[x + 1], \
								&stp->bres, &stp->data);
				}
				else
					ft_bresenham(stp->map.npts[x], stp->map.npts[x + 1], \
							&stp->bres, &stp->data);
			}
			if (x < stp->lastrow)
			{
				if (stp->clip)
				{
					if (!check_pts(stp->map.npts[x]) && !check_pts(stp->map.npts[x + stp->linelen]))
						ft_bresenham(stp->map.npts[x], stp->map.npts[x +\
							   	stp->linelen], &stp->bres, &stp->data);
				}
				else
					ft_bresenham(stp->map.npts[x], stp->map.npts[x +\
						   	stp->linelen], &stp->bres, &stp->data);
			}
			x++;
		}
		y++;
	}
}

void	display_help(t_setup *stp)
{
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, 5, 5, 0xFF0000, \
			"w, a, s, d = Move camera");
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, 5, 25, 0xFF0000, \
			"up / down arrows = Zoom");
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, 5, 45, 0xFF0000, \
			"i, j, k, l = Rotation");
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, 5, 65, 0xFF0000, \
			"r = Switch Dots/Lines");
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, 5, 85, 0xFF0000, \
			"p = Switch pers Orthographique / Conique");
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, 5, 105, 0xFF0000, \
			"b = Back to default / Reset");
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, 5, 125, 0xFF0000, \
			"left/right arrows = increase elevation");
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, 5, 145, 0xFF0000, \
			"Esc = Exit FDF");
}
