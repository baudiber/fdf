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


int		parse_lines(t_rows **rows)
{
	t_rows	*tmp;
	int		len;
	int		len2;

	tmp = *rows;
	len = ft_tablen(tmp->tab);		
	while (tmp)
	{
		tmp = tmp->next;
		if (!tmp->tab)
			break;
		len2 = ft_tablen(tmp->tab);
		if (len != len2)
			return (1);
	}
//	tmp = *rows;
//	while (tmp->tab)
//	{
//		len = 0;
//		while (len < len2)
//		{
//			//printf("%d\n", ft_get_hexa(tmp->tab[len]));
//			len++;
//		}
//		tmp = tmp->next;
//	}
	return (0);
}

void	parser(char *av)
{
	int		fd;
	t_rows	*rows;
	t_setup	setup;
	t_rows	*tmp;

	rows = (t_rows *)malloc(sizeof(t_rows));
	if (!rows)
		ft_errors(3);
	tmp = rows;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_errors(1);
	while ((get_next_line(fd, &tmp->line)) > 0)
	{
		setup.ynb++;
		tmp->tab = ft_strsplit(tmp->line, ' ');
		tmp->next = (t_rows *)malloc(sizeof(t_rows));
		if (!tmp->next)
			ft_errors(3);
		tmp = tmp->next;
		tmp->line = NULL;
	}
	tmp->next = NULL;
	//tmp = NULL ? 
	if (parse_lines(&rows))
		ft_errors(2);
}
