/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:18:22 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/08 00:29:03 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit (0);
	return (0);
}


void	display(t_setup *setup)
{
	int		i;

	create_window("FDF", 1024, 768, setup);
	setup->img_ptr = mlx_new_image(setup->mlx_ptr, setup->width, setup->height);
	setup->data = (int *)mlx_get_data_addr(setup->img_ptr, &setup->bpx, &setup->s_line, &setup->ed);
	i = 0;
	while (i < setup->ptnb - 1) 
	{
		ft_bresenham(setup->points[i].x, setup->points[i].y, setup->points[i + 1].x, setup->points[i + 1].y, setup);
		if (i < setup->lastrow)
			ft_bresenham(setup->points[i].x, setup->points[i].y, setup->points[i + setup->ptnb / setup->ynb].x, setup->points[i + setup->ptnb / setup->ynb].y, setup);
		i++;
	}
	mlx_put_image_to_window(setup->data, setup->win_ptr, setup->img_ptr, 0, 0);
	mlx_key_hook(setup->win_ptr, deal_key, (void *)0);
	mlx_loop(setup->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_setup	setup;

	if (ac != 2)
		ft_putendl("usage : ./fdf <map>");
	else if (!ft_strstr(av[1], ".fdf"))
		ft_putendl("wrong file format");
	else
	{
		setup.mlx_ptr = mlx_init();
		parser(av[1], &setup); 
		//printf("test\n");
		env_points(&setup);
		//display_splash(&setup);
		display(&setup);
	}
	return (0);
}
