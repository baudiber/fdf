/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 17:30:52 by baudiber          #+#    #+#             */
/*   Updated: 2018/10/23 14:53:07 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_errors(int type)
{
	if (type == 1)
	{
		write(1, "open() failed\n", 14);
		exit(0);
	}
	else if (type == 2)
	{
		write(1, "invalid map\n", 12);
		exit(0);
	}
	else if (type == 3)
	{
		write(1, "malloc error\n", 13);
		exit(0);
	}
}

/*
** free the map arrays
*/

void	free_all(t_setup *stp)
{
	free(stp->map.npts);
	free(stp->map.tpts);
}

/*
** free the linked list
*/

void	free_ll(t_rows *head)
{
	t_rows	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
