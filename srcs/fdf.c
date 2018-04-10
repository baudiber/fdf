/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:18:22 by baudiber          #+#    #+#             */
/*   Updated: 2018/04/10 19:02:56 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_points(char ***tab, t_point **point)
{
	int		i;
	
	i = 0;
	while (tab[i])
	{
		(*point)[i].x = 
		i++;
	}
}

void	parser(int fd, t_point **setup)
{
	char	**tab;
	char	*line;
	int		fd;

	(*setup).start = setup.rows;
	(*setup).ynb = 0;
	while (get_next_line(fd, &line))
	{
		if (!(*setup).rows && !((*setup).rows = \
					(t_rows *)malloc(sizeof(t_point) * 1)))
			exit (0);
		tab = ft_strsplit(line, ' ');
		(*setup).rows->ptnb = ft_tablen(tab);
		if (!((*setup).rows->point = (t_point *)malloc(sizeof(t_point) * \
			(*setup).rows-> ptnb)) || !((*setup).rows->next = \
		   	(t_rows)malloc(sizeof(t_rows))))
			exit (0);
		get_rows(&tab, &(*setup).rows->point);
		(*setup).rows = (*setup).rows->next;
		(*setup).rows->next = NULL;
		free(line);
		(*setup).ynb++;
	}
	return (0);
}

int		deal_key(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit (0);
	return (0);
}

void	display(t_point *setup)
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
	t_setup setup;

	setup = NULL;
	if (ac != 2)
		ft_putendl("usage : ./fdf <map>");
	else if (!ft_strstr(av[1], ".fdf"))
		ft_putendl("wrong file format");
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{	
			write(1, "open() failed\n", 14);
			return (1);
		}
		parser(fd, &setup); 
		display(setup);
	}
	return (0);
}
