/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 23:19:25 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/23 01:39:25 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_setup	stp;

	if (ac != 2)
		ft_putendl("usage : ./fdf <map>");
	else if (!ft_strstr(av[1], ".fdf"))
		ft_putendl("wrong file format");
	else
	{
		ft_bzero(&stp, sizeof(t_setup));
		stp.av = av[1];
		parser(&stp); 
		printf("ptnb: %d\n", stp.ptnb);
		init_all(&stp);
		fdf(&stp);
		//display(&stp);
	}
	return (0);
}
