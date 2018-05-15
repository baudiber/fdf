/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:54:27 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/15 19:04:47 by baudiber         ###   ########.fr       */
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
			setup->pts[ptcnt].color = point_color(tmp->tab[i]);
			setup->pts[ptcnt].vect.x = i * 30;
			setup->pts[ptcnt].vect.y = y * 30;
			setup->pts[ptcnt].vect.z = ft_atoi(tmp->tab[i]);
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
		if ((str[i] != ' ' && str[i] != 'x' && str[i] != ',' && str[i] != '-')\
			   	&& (str[i] < '0' || str[i] > '9') && \
				(str[i] < 'A' || str[i] > 'F'))
			return (1);
		i++;
	}
	return (0);
}

int				parse_lines(t_rows **rows, t_setup *setup)
{
	int		len2;
	t_rows	*tmp;

	tmp = *rows;
	setup->linelen = ft_tablen(tmp->tab);		
	setup->ptnb = setup->ynb * setup->linelen;
	setup->pts = (t_point *)malloc(sizeof(t_point) * setup->ptnb);
	while (tmp->tab)
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
	if (!(rows = (t_rows *)malloc(sizeof(t_rows))))
		ft_errors(3);
	tmp = rows;
	if ((fd = open(av, O_RDONLY)) == -1)
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
	}
	tmp->tab = NULL;
	if (ret == -1 || parse_lines(&rows, setup))
		ft_errors(2);
	printf("ptnb: %d\n", setup->ptnb);
}
