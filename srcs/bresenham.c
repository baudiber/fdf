/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:25:28 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/28 00:10:38 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham2(t_bres *bres, int **img, unsigned int color)
{
	bres->cumul = bres->dy / 2;
	while (bres->i <= bres->dy) 
	{
		bres->y += bres->yinc;
		bres->cumul += bres->dx;
		if (bres->cumul >= bres->dy) 
		{
			bres->cumul -= bres->dy;
			bres->x += bres->xinc; 
		}
		check_and_draw(img, hpt(bres->x + WIDTH / 2, \
					bres->y + HEIGHT / 2, 0, 0), color);
		bres->i++;
	} 
}

void	ft_bresenham1(t_bres *bres, int **img, unsigned int color)
{
	bres->cumul = bres->dx / 2;
	while (bres->i <= bres->dx) 
	{
		bres->x += bres->xinc;
		bres->cumul += bres->dy;
		if (bres->cumul >= bres->dx) 
		{
			bres->cumul -= bres->dx;
			bres->y += bres->yinc; 
		}
		check_and_draw(img, hpt(bres->x + WIDTH / 2, \
					bres->y + HEIGHT / 2, 0, 0), color);
		bres->i++;
	} 
}

void	ft_bresenham(t_hpt p1, t_hpt p2, t_bres *bres, int **img)
{
	bres->x = p1.x;
	bres->y = p1.y;
	bres->dx = p2.x - p1.x;
	bres->dy = p2.y - p1.y;
	bres->xinc = (bres->dx > 0) ? 1 : -1;
	bres->yinc = (bres->dy > 0) ? 1 : -1;
	bres->dx = ABS(bres->dx);
	bres->dy = ABS(bres->dy);
	bres->i = 1;
	check_and_draw(img, hpt(bres->x + WIDTH / 2, bres->y + HEIGHT / 2, 0, 0), \
			p2.color);
	if (bres->dx > bres->dy) 
		ft_bresenham1(bres, img, p2.color);
	else 
		ft_bresenham2(bres, img, p2.color);
}
