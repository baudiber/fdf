/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:50:18 by baudiber          #+#    #+#             */
/*   Updated: 2018/04/12 22:56:33 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_lines(t_rows **rows)
{
	t_rows	*tmp;

	tmp = *rows;
	while (tmp)
	{
		tmp = tmp->next;
	}
}

void	parser(char *av)
{
	int		fd;
	t_rows	*rows;
	t_rows	*tmp;

	rows = (t_rows *)malloc(sizeof(t_rows));
	tmp = rows;
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		write(1, "open() failed\n", 14);
		return ;
	}
	while ((get_next_line(fd, &tmp->line)) > 0)
	{
		tmp->tab = ft_strsplit(tmp->line, ' ');
		tmp->next = (t_rows *)malloc(sizeof(t_rows));
		tmp = tmp->next;
		tmp->line = NULL;
	}
	tmp->next = NULL;
	parse_lines(&rows);
}
