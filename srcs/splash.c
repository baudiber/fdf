/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:42:03 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/07 17:52:25 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

	create_window("BAUDIBER PRESENTS", 800, 600, setup);
	setup->img_ptr = mlx_new_image(setup->mlx_ptr, setup->width, setup->height);
	setup->data = (int *)mlx_get_data_addr(setup->img_ptr, &setup->bpx, &setup->s_line, &setup->ed);
	i = 0;
	j = 0xFFFFFFFF;
	while (i < setup->width)
	{
		setup->data[setup->width * setup->height / 2 + i] = j;
		if (i < setup->width / 2 && j > 0x00FFFFFF)
			j -= 0x01000000;
		if (i >= setup->width - (setup->width * 32 / 100) && j < 0xFFFFFFFF)
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


