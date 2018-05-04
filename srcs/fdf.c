/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:18:22 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/04 18:50:09 by baudiber         ###   ########.fr       */
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

void	create_window(char *str, int width, int height, t_setup *setup)
{
	setup->width = width;
	setup->height = height;
	setup->win_ptr = mlx_new_window(setup->mlx_ptr, width, height, str);
}

void	display(t_setup *setup)
{
	int		i;

	mlx_destroy_image(setup->mlx_ptr, setup->img_ptr);
//	mlx_clear_window(setup->mlx_ptr, setup->win_ptr);
	mlx_destroy_window(setup->mlx_ptr, setup->win_ptr);
	create_window("FDF", 1024, 768, setup);
	setup->img_ptr = mlx_new_image(setup->mlx_ptr, W_WIDTH, W_HEIGHT);
	setup->data = (int *)mlx_get_data_addr(setup->img_ptr, &setup->bpx, &setup->s_line, &setup->ed);
	i = 0;
	while (i < setup->ptnb - 1) 
	{
		//ft_bresenham(setup->points[i].x, setup->points[i].y, setup->points[i + 1].x, setup->points[i + 1].y, setup);
		ft_bresenham(100, 100, 550, 150, setup);
		i++;
	}
	mlx_put_image_to_window(setup->data, setup->win_ptr, setup->img_ptr, 0, 0);
	mlx_key_hook(setup->win_ptr, deal_key, (void *)0);
	mlx_loop(setup->mlx_ptr);
//	ft_wu(xa, ya, xb, yb);
}

int		mouse_hook(int button, int x, int y, void *setup)
{
	(void)x;
	(void)y;
	if (button == 1)
		display(setup);
	return (0);
}


void	display_splash(t_setup *setup)
{
	int		i;
	unsigned int		j;

	setup->win_ptr = mlx_new_window(setup->mlx_ptr, W_WIDTH, W_HEIGHT, "SPLASH SCREEN");
	setup->img_ptr = mlx_new_image(setup->mlx_ptr, W_WIDTH, W_HEIGHT);
	setup->data = (int *)mlx_get_data_addr(setup->img_ptr, &setup->bpx, &setup->s_line, &setup->ed);
	i = 0;
	j = 0xFFFFFFFF;
	while (i < W_WIDTH)
	{
		setup->data[W_WIDTH * W_HEIGHT / 2 + i] = j;
		if (i < W_WIDTH / 2 && j > 0x00FFFFFF)
			j -= 0x01000000;
		if (i >= W_WIDTH - (W_WIDTH * 32 / 100) && j < 0xFFFFFFFF)
			j += 0x01000000;
		i++;
	}
	mlx_put_image_to_window(setup->data, setup->win_ptr, setup->img_ptr, 0, 0);
	mlx_string_put(setup->mlx_ptr, setup->win_ptr, 330, 280, 0xFFFFFF, "Wireframe v0.1");
	mlx_string_put(setup->mlx_ptr, setup->win_ptr, 290, 400, 0xFFFFFF, "Press Mouse 1 to start");
	mlx_key_hook(setup->win_ptr, deal_key, (void *)0);
	mlx_mouse_hook(setup->win_ptr, mouse_hook, setup);
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
		display_splash(&setup);
		display(&setup);
	}
	return (0);
}
