/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:18:22 by baudiber          #+#    #+#             */
/*   Updated: 2018/04/12 21:49:43 by baudiber         ###   ########.fr       */
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

void	display(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1024, "~  <baudiber>'s fdf  ~");
	//mlx_pixel_put(mlx_ptr, win_ptr, 1920 / 2, 1024 / 2, 0xFFFFFF);
	//mlx_string_put(mlx_ptr, win_ptr, 1920 / 2, 1024 / 2, 0xFFFFFF, "kikou");
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		ft_putendl("usage : ./fdf <map>");
	else if (!ft_strstr(av[1], ".fdf"))
		ft_putendl("wrong file format");
	else
	{
		parser(av[1]); 
		//display();
	}
	return (0);
}
