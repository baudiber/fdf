/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:50:18 by baudiber          #+#    #+#             */
/*   Updated: 2018/04/11 18:54:48 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parser(char *av)
{
	int		fd;
	t_rows	*rows;

	rows = (t_rows *)malloc(sizeof(t_rows));
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		write(1, "open() failed\n", 14);
		return ;
	}
	while ((get_next_line(fd, &rows->line)) > 0)
	{
		rows->next = (t_rows *)malloc(sizeof(t_rows));
		rows = rows->next;
	}
}
