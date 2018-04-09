/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:18:22 by baudiber          #+#    #+#             */
/*   Updated: 2018/04/09 23:52:18 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h> 
#include "libft.h"

int		**parser(char *str, int fd, t_point *points)
{
	int		ret;
	int		i;
	int		nbpt;
	char	*line;

	while (ret = get_next_line(fd, &line))
	{
		i = 0;	
		while (line[i])
		{
			if (line[i] == '-' || (ft_isdigit(line[i]))
			i++;
		}
		free(line);
	}
	/* check if map is correct first
	** open map to parse with gnl
	** number of columns must be the same (in the int tab)
	** can't be anything else than space or number
	** if not number add previous number to inttab
	*/

	(void)str;
	(void)map;
	return (0);
}

int		deal_key(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit (0);
	return (0);
}

void	display(t_point *points)
{
	void	*mlx_ptr;
	void	*win_ptr;

	(void)map;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1024, "~  <baudiber>'s fdf  ~");
	//mlx_pixel_put(mlx_ptr, win_ptr, 1920 / 2, 1024 / 2, 0xFFFFFF);
	//mlx_string_put(mlx_ptr, win_ptr, 1920 / 2, 1024 / 2, 0xFFFFFF, "kikou");
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}

int		main(int ac, char **av)
{
	t_point	*points;
	int		fd;
	//void	*mlx_ptr;
	//void	*win_ptr;
	
	points = NULL;
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
		map = parser(av[1], fd, &points); 
		display(points);
	}
	return (0);
}
