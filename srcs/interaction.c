/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:30:12 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/09 18:31:45 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int		deal_key(int key, void *param)
{
	(void)param;
	/*
	if (key == 13)
		//w
	if (key == 1)
		//s
	if (key == 0)
		//a
	if (key == 2)
		//d
	if (key == 126)
		//up
	if (key == 125)
		//down
	if (key == 123)
		//left
	if (key == 124)
		//right
	if (key == 4)
		//display help
	*/
	if (key == 53)
		exit (0);
	return (0);
}
