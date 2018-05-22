/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:30:12 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/20 19:40:15 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int		deal_key(int key, t_setup *stp)
{
	if (key == 126)
	{
		redraw(stp);
		printf("^\n");
	}
	if (key == 125)
	{
		redraw(stp);
		printf("v\n");
	}
	if (key == 123)
	{
		printf("<\n");
	}
	if (key == 124)
	{
		printf(">\n");
	}
	/*
	if (key == 13)
		//w
	if (key == 1)
		//s
	if (key == 0)
		//a
	if (key == 2)
		//d
	if (key == 4)
		//display help
	*/
	if (key == 53)
		exit (0);
	return (0);
}
