/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:18:22 by baudiber          #+#    #+#             */
/*   Updated: 2018/04/25 19:44:40 by baudiber         ###   ########.fr       */
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

//	ft_bresenham(xa, ya, xb, yb);
	ft_wu(xa, ya, xb, yb);
	i = 0;
	while (i < setup->ptnb)
	{
//		printf("%d\n", setup->points[i].y);
		i++;
	}
}

void	display_splash(void)
{
	int		i;
	unsigned int		j;
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "~  <baudiber>'s fdf  ~");
	i = 0;
	j = 0xFFFFFFFF;
	while (i < 800)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, 600 / 2, j);
		if (i < 400 && j > 0x00FFFFFF)
			j -= 0x01000000;
		if (i >= 550 && j < 0xFFFFFFFF)
			j += 0x01000000;
		i++;
	}
	mlx_string_put(mlx_ptr, win_ptr, 330, 280, 0xFFFFFF, "Wireframe v0.1");
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
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
		parser(av[1], &setup); 
		//display_splash();
		display(&setup);
	}
	return (0);
}
