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

t_vect	matrix_multiply(t_vect v, t_setup *stp)
{
	t_vect	res;

	res.x = v.x * stp->matrix[0][0] + v.y * stp->matrix[1][0] + v.z * stp->matrix[2][0] + 1 * stp->matrix[3][0];
	res.y = v.x * stp->matrix[0][1] + v.y * stp->matrix[1][1] + v.z * stp->matrix[2][1] + 1 * stp->matrix[3][1];
	res.z = v.x * stp->matrix[0][2] + v.y * stp->matrix[1][2] + v.z * stp->matrix[2][2] + 1 * stp->matrix[3][2];
	return (res);
}

void	ft_lookat(t_setup *stp)
{
	t_vect	cam;
	t_vect	forward;
	t_vect	right;
	t_vect	up;
	t_vect	tmp;

	cam.x = 1;
	cam.y = 0;
	cam.z = 1;
	tmp.x = 0;
	tmp.y = 1;
	tmp.z = 0;
	forward = normalize_vect(sub_vects(cam, stp->pts[stp->ptnb].vect));
	right = cross_product(tmp, forward);
	up = cross_product(forward, right);
	stp->matrix[0][0] = right.x;
	stp->matrix[0][1] = right.y;
	stp->matrix[0][2] = right.z;
	stp->matrix[1][0] = up.x;
	stp->matrix[1][1] = up.y;
	stp->matrix[1][2] = up.z;
	stp->matrix[2][0] = forward.x;
	stp->matrix[2][1] = forward.y;
	stp->matrix[2][2] = forward.z;
	stp->matrix[3][0] = cam.x;
	stp->matrix[3][1] = cam.y;
	stp->matrix[3][2] = cam.z;
}
/*
void	display(t_setup *stp)
{
	int		i;
	t_vect	tmp;
	t_vect	tmp1;
	t_vect	tmp2;

	ft_lookat(stp);
	create_window("FDF", 1024, 768, stp);
	stp->img_ptr = mlx_new_image(stp->mlx_ptr, stp->width, stp->height);
	stp->data = (int *)mlx_get_data_addr(stp->img_ptr, &stp->bpx, &stp->s_line, &stp->ed);
	i = 0;
	while (i < stp->ptnb - 1) 
	{
		tmp = matrix_multiply(stp->pts[i].vect, stp);
		tmp1 = matrix_multiply(stp->pts[i + 1].vect, stp);
		ft_bresenham(tmp.x, tmp.y, tmp1.x, tmp1.y, stp);
		if (i < stp->lastrow)
		{
			tmp2 = matrix_multiply(stp->pts[i + stp->ptnb / stp->ynb].vect, stp);
			printf("x:%d y:%d\n", (int)tmp2.x, (int)tmp2.y);
			ft_bresenham(tmp.x, tmp.y, tmp2.x, tmp2.y, stp);
		}
		i++;
	}
	mlx_put_image_to_window(stp->data, stp->win_ptr, stp->img_ptr, 0, 0);
	mlx_string_put(stp->mlx_ptr, stp->win_ptr, 850, 740, 0xF0F0F0, "Press h for help");
	mlx_key_hook(stp->win_ptr, deal_key, (void *)0);
	mlx_loop(stp->mlx_ptr);
}

*/

void	display(t_setup *stp)
{
	int		i;

	create_window("FDF", 1024, 768, stp);
	stp->img_ptr = mlx_new_image(stp->mlx_ptr, stp->width, stp->height);
	stp->data = (int *)mlx_get_data_addr(stp->img_ptr, &stp->bpx, &stp->s_line, &stp->ed);
	i = 0;
	while (i < stp->ptnb - 1) 
	{
		ft_bresenham(stp->pts[i].vect.x, stp->pts[i].vect.y, stp->pts[i + 1].vect.x, stp->pts[i + 1].vect.y, stp);
		if (i < stp->lastrow)
			ft_bresenham(stp->pts[i].vect.x, stp->pts[i].vect.y, stp->pts[i + stp->ptnb / stp->ynb].vect.x, stp->pts[i + stp->ptnb / stp->ynb].vect.y, stp);
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
