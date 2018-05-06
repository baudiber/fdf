/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:54:27 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/06 23:49:59 by baudiber         ###   ########.fr       */
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
			setup->points[ptcnt].x = i * 10;
			setup->points[ptcnt].y = y * 10;
			ptcnt++;
			i++;
		}
		y++;
		tmp = tmp->next;
	}
}

int				check_line(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != ' ' && str[i] != 'x' && str[i] != ',') && (str[i] < '0' \
				|| str[i] > '9') && (str[i] < 'A' || str[i] > 'F'))
			return (1);
		i++;
	}
	return (0);
}

int				parse_lines(t_rows **rows, t_setup *setup)
{
	t_rows	*tmp;
	int		len2;

	tmp = *rows;
	setup->linelen = ft_tablen(tmp->tab);		
	setup->ptnb = setup->ynb * setup->linelen;
	setup->points = (t_point *)malloc(sizeof(t_point) * setup->ptnb);
	while (tmp)
	{
		tmp = tmp->next;
		if (!tmp->tab)
			break;
		len2 = ft_tablen(tmp->tab);
		if (setup->linelen != len2)
			return (1);
	}
	get_points(rows, setup);
	return (0);
}

void			parser(char *av, t_setup *setup)
{
	int		fd;
	int		ret;
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
	while ((ret = get_next_line(fd, &tmp->line)) > 0)
	{
		setup->ynb++;
		if (check_line(tmp->line))
			ft_errors(2);
		tmp->tab = ft_strsplit(tmp->line, ' ');
		tmp->next = (t_rows *)malloc(sizeof(t_rows));
		if (!tmp->next)
			ft_errors(3);
		tmp = tmp->next;
		tmp->line = NULL;
	}
	tmp->next = NULL;
	//tmp = NULL ? 
	if (ret == -1 || parse_lines(&rows, setup))
		ft_errors(2);
	printf("ptnb: %d\n", setup->ptnb);
}
