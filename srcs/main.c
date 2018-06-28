/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 23:19:25 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/28 02:15:52 by baudiber         ###   ########.fr       */
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
		parser(&stp, stp.av); 
		printf("ptnb: %d\n", stp.ptnb);
		printf("highest: %d\n", stp.map.highest);
		init_all(&stp);
		fdf(&stp);
	}
	return (0);
}
