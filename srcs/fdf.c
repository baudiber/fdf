/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:18:22 by baudiber          #+#    #+#             */
/*   Updated: 2018/04/28 19:52:10 by baudiber         ###   ########.fr       */
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
	int		xa = 100;
	int		ya = 100;
	int		xb = 500;
	int		yb = 150;

	//setup->win_ptr = mlx_new_window(setup->mlx_ptr, 1024, 768, "~  <baudiber>'s fdf  ~");
	ft_bresenham(xa, ya, xb, yb, setup);
	mlx_key_hook(setup->win_ptr, deal_key, (void *)0);
	mlx_loop(setup->mlx_ptr);

//	ft_wu(xa, ya, xb, yb);
	i = 0;
	while (i < setup->ptnb)
	{
//		printf("%d\n", setup->points[i].y);
		i++;
	}
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
	void	*win_ptr;
	void	*img_ptr;
	int		data;
	int		bpx;
	int		sl;
	int		endian;

	win_ptr = mlx_new_window(setup->mlx_ptr, 800, 600, "SPLASH SCREEN");
	img_ptr = mlx_new_image(setup->mlx_ptr, 800, 600);
	data = (int)mlx_get_data_addr(img_ptr, &bpx, &sl, &endian);
	i = 0;
	j = 0xFFFFFFFF;
	while (i < 800)
	{
		mlx_pixel_put(setup->mlx_ptr, win_ptr, i, 600 / 2, j);
		if (i < 400 && j > 0x00FFFFFF)
			j -= 0x01000000;
		if (i >= 550 && j < 0xFFFFFFFF)
			j += 0x01000000;
		i++;
	}
	mlx_string_put(setup->mlx_ptr, win_ptr, 330, 280, 0xFFFFFF, "Wireframe v0.1");
	mlx_string_put(setup->mlx_ptr, win_ptr, 290, 400, 0xFFFFFF, "Press Mouse 1 to start");
	//mlx_mouse_hook(win_ptr, mouse_hook, setup);
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
