/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:18:22 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/09 18:49:09 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_lookat(t_setup *stp)
{
	t_vect	cam;
	t_vect	forward;
	t_vect	right;
	t_vect	up;
	double	matrix[4][4];

	cam.x = 100;
	cam.y = -100;
	cam.z = 400;
}

void	display(t_setup *stp)
{
	int		i;

	create_window("FDF", 1024, 768, stp);
	stp->img_ptr = mlx_new_image(stp->mlx_ptr, stp->width, stp->height);
	stp->data = (int *)mlx_get_data_addr(stp->img_ptr, &stp->bpx, &stp->s_line, &stp->ed);
	i = 0;
	while (i < stp->ptnb - 1) 
	{
		ft_bresenham(stp->pts[i].x, stp->pts[i].y, stp->pts[i + 1].x, stp->pts[i + 1].y, stp);
		if (i < stp->lastrow)
			ft_bresenham(stp->pts[i].x, stp->pts[i].y, stp->pts[i + stp->ptnb / stp->ynb].x, stp->pts[i + stp->ptnb / stp->ynb].y, stp);
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
		//printf("test\n");
		env_points(&stp);
		display_splash(&stp);
		display(&stp);
	}
	return (0);
}
