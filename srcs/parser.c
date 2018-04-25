/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:54:27 by baudiber          #+#    #+#             */
/*   Updated: 2018/04/25 17:38:17 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

unsigned int	point_color(char *str)
{
	unsigned int	color;

	color = ft_getcolor(str);
	return ((color) ? color : 0xFFFFFF);
}

void			get_points(t_rows **rows, t_setup *setup)
{
	t_rows	*tmp;
	int		len;
	int		i;
	int		y;
	int		ptcnt;

	tmp = *rows;
	y = 0;
	ptcnt = 0;
	len = ft_tablen(tmp->tab);		
	while (tmp->tab)
	{
		i = 0;
		while (i < len)
		{
			setup->points[ptcnt].color = point_color(tmp->tab[i]);
			setup->points[ptcnt].x = i;
			setup->points[ptcnt].y = y;
			ptcnt++;
			i++;
		}
		y++;
		tmp = tmp->next;
	}
}

int				parse_lines(t_rows **rows, t_setup *setup)
{
	t_rows	*tmp;
	int		len;
	int		len2;

	tmp = *rows;
	len = ft_tablen(tmp->tab);		
	setup->ptnb = setup->ynb * len;
	setup->points = (t_point *)malloc(sizeof(t_point) * setup->ptnb);
	while (tmp)
	{
		tmp = tmp->next;
		if (!tmp->tab)
			break;
		len2 = ft_tablen(tmp->tab);
		if (len != len2)
			return (1);
	}
	get_points(rows, setup);
	return (0);
}

void			parser(char *av, t_setup *setup)
{
	int		fd;
	t_rows	*rows;
	t_rows	*tmp;

	setup->ynb = 0;
	rows = (t_rows *)malloc(sizeof(t_rows));
	if (!rows)
		ft_errors(3);
	tmp = rows;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_errors(1);
	while ((get_next_line(fd, &tmp->line)) > 0)
	{
		setup->ynb++;
		tmp->tab = ft_strsplit(tmp->line, ' ');
		tmp->next = (t_rows *)malloc(sizeof(t_rows));
		if (!tmp->next)
			ft_errors(3);
		tmp = tmp->next;
		tmp->line = NULL;
	}
	tmp->next = NULL;
	//tmp = NULL ? 
	if (parse_lines(&rows, setup))
		ft_errors(2);
	printf("ptnb: %d\n", setup->ptnb);
}
