/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 23:18:22 by baudiber          #+#    #+#             */
/*   Updated: 2018/03/20 00:34:31 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h> 
#include "libft/libft.h"

int		parser(char *str, int ***map)
{
	/* check if map is correct first
	** open map to parse with gnl
	** number of columns must be the same (in the int tab)
	** can be negative !	 	
	** can't be anything else than space or number
	** if not number add previous number to inttab
	*/

	ft_putendl("loul");		
	(void)str;
	(void)map;
	return (0);
}

int		main(int ac, char **av)
{
	//void	*mlx_ptr;
	//void	*win_ptr;
	int		**map;

	if (ac != 2)
		ft_putendl("usage : ./fdf <map>");		
	else if (!ft_strstr(av[1], ".fdf"))
		ft_putendl("wrong file format");
	else
		parser(av[1], &map); 
	return (0);
}
