/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:18:22 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/17 21:05:44 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	matrix_multiplication(t_setup *stp)
{
	int		i;

	i = 0;
	while (i < stp->ptnb)
	{
		stp->npts[i].vect.x = stp->mat[0][0] * stp->pts[i].vect.x + stp->mat[0][1] * stp->pts[i].vect.y + stp->mat[0][2] * stp->pts[i].vect.z;
		stp->npts[i].vect.y = stp->mat[1][0] * stp->pts[i].vect.x + stp->mat[1][1] * stp->pts[i].vect.y + stp->mat[1][2] * stp->pts[i].vect.z;
		stp->npts[i].vect.z = stp->mat[2][0] * stp->pts[i].vect.x + stp->mat[2][1] * stp->pts[i].vect.y + stp->mat[2][2] * stp->pts[i].vect.z;
		i++;
	}
}

void	display(t_setup *stp)
{
	int		i;
	int		j;

	create_window("FDF", 1024, 768, stp);
	stp->img_ptr = mlx_new_image(stp->mlx_ptr, stp->width, stp->height);
	stp->data = (int *)mlx_get_data_addr(stp->img_ptr, &stp->bpx, &stp->s_line, &stp->ed);
	get_matrix(stp->q0, stp);
	matrix_multiplication(stp);
	i = 0;
	j = 1;
	while (i < stp->ptnb - 1) 
	{
		j++;
		ft_bresenham(stp->npts[i].vect.x + 200, stp->npts[i].vect.y + 200, stp->npts[i + 1].vect.x + 200, stp->npts[i + 1].vect.y + 200, stp);
		if (i < stp->lastrow)
			ft_bresenham(stp->npts[i].vect.x + 200, stp->npts[i].vect.y + 200, stp->npts[i + stp->ptnb / stp->ynb].vect.x + 200, stp->npts[i + stp->ptnb / stp->ynb].vect.y + 200, stp);
		i++;
	}
	mlx_put_image_to_window(stp->data, stp->win_ptr, stp->img_ptr, 0, 0);
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, 850, 740, 0xF0F0F0, "Press h for help");
	mlx_key_hook(stp->win_ptr, deal_key, (void *)0);
	mlx_loop(stp->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_setup	stp;

	if (ac != 2)
		ft_putendl("usage : ./fdf <map>");
	else if (!ft_strstr(av[1], ".fdf"))
		ft_putendl("wrong file format");
	else
	{
		stp.mlx_ptr = mlx_init();
		parser(av[1], &stp); 
		env_points(&stp);
		display_splash(&stp);
		display(&stp);
	}
	return (0);
}
