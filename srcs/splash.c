/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:42:03 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/09 17:31:44 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_hook(int button, int x, int y, t_setup *stp)
{
	(void)x;
	if (button == 1 && y > 1)
	{
		mlx_destroy_window(stp->mlx_ptr, stp->win_ptr);
		display(stp);
	}
	return (0);
}

void	splash_art(t_setup *stp)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0xFFFFFFFF;
	while (i < stp->width)
	{
		stp->data[stp->width * stp->height / 2 + i] = j;
		if (i < stp->width / 2 && j > 0x00FFFFFF)
			j -= 0x01000000;
		if (i >= stp->width - (stp->width * 32 / 100) && j < 0xFFFFFFFF)
			j += 0x01000000;
		i++;
	}
}

void	display_splash(t_setup *stp)
{
	create_window("BAUDIBER PRESENTS", 800, 600, stp);
	stp->img_ptr = mlx_new_image(stp->mlx_ptr, stp->width, stp->height);
	stp->data = (int *)mlx_get_data_addr(stp->img_ptr, &stp->bpx, &stp->s_line, &stp->ed);
	splash_art(stp);
	mlx_put_image_to_window(stp->data, stp->win_ptr, stp->img_ptr, 0, 0);
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, 330, 280, 0xFFFFFF, "Wireframe v0.1");
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, 290, 400, 0xFFFFFF, "Press Mouse 1 to start");
	mlx_key_hook(stp->win_ptr, deal_key, (void *)0);
	mlx_mouse_hook(stp->win_ptr, mouse_hook, stp);
	mlx_loop(stp->mlx_ptr);
}


