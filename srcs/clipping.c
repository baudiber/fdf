/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 00:27:28 by baudiber          #+#    #+#             */
/*   Updated: 2018/10/23 14:45:59 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_pts(t_hpt pt)
{
	pt.x += WIDTH / 2;
	pt.y += HEIGHT / 2;
	if ((int)pt.x <= 0 || (int)pt.x > WIDTH - 2 || (int)pt.y <= 0 || \
			(int)pt.y > HEIGHT - 2)
		return (1);
	return (0);
}

/*
** this function displays the lines that fit in the screen, not the ones that
** have one of the points outside of it
*/

void	display_linesclip(t_setup *stp)
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
				if (!check_pts(stp->map.npts[x]) && \
						!check_pts(stp->map.npts[x + 1]))
					ft_bresenham(stp->map.npts[x], stp->map.npts[x + 1], \
						&stp->bres, &stp->data);
			if (x < stp->lastrow)
				if (!check_pts(stp->map.npts[x]) && \
						!check_pts(stp->map.npts[x + stp->linelen]))
					ft_bresenham(stp->map.npts[x], stp->map.npts[x +\
						stp->linelen], &stp->bres, &stp->data);
			x++;
		}
		y++;
	}
}
