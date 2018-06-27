/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:54:27 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/26 16:48:22 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

unsigned int	point_color(char *str)
{
	unsigned int	color;

	color = ft_getcolor(str);
	return ((color) ? color : 0xFFFFFF);
}

void			get_points2(t_hpt *pt, char *str, int i, int y)
{
	pt->color = point_color(str);
	pt->x = i;
	pt->y = y;
	pt->z = ft_atoi(str);
	pt->w = 1.0;
}

static void		get_points(t_rows **rows, t_setup *stp)
{
	t_rows	*tmp;
	int		i;
	int		y;
	int		ptcnt;

	tmp = *rows;
	y = 0;
	ptcnt = 0;
	while (tmp->tab)
	{
		i = 0;
		while (i < stp->linelen)
		{
			get_points2(&stp->map.pts[ptcnt], tmp->tab[i], i, y);
			stp->map.highest = (ABS(stp->map.pts[ptcnt].z) > stp->map.highest)\
							   ? ABS(stp->map.pts[ptcnt].z) : stp->map.highest;
			ptcnt++;
			i++;
		}
		ft_freetab(tmp->tab);
		y++;
		tmp = tmp->next;
	}
}

static int		check_line(char *str)
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

static int		parse_lines(t_rows **rows, t_setup *stp)
{
	int		len2;
	t_rows	*tmp;

	tmp = *rows;
	stp->linelen = ft_tablen(tmp->tab);		
	while (tmp->tab)
	{
		stp->ynb++;
		tmp = tmp->next;
		if (!tmp->tab)
			break;
		len2 = ft_tablen(tmp->tab);
		if (stp->linelen != len2)
			return (1);
	}
	stp->ptnb = stp->ynb * stp->linelen;
	if (!(stp->map.pts = (t_hpt *)malloc(sizeof(t_hpt) * stp->ptnb)))
		ft_errors(3);	
	get_points(rows, stp);
	free_ll(*rows);
	return (0);
}

void			parser(t_setup *stp, char *map)
{
	int		fd;
	int		ret;
	t_rows	*rows;
	t_rows	*tmp;

	stp->ynb = 0;
	if (!(rows = (t_rows *)malloc(sizeof(t_rows))))
		ft_errors(3);
	tmp = rows;
	if ((fd = open(map, O_RDONLY)) == -1)
		ft_errors(1);
	while ((ret = get_next_line(fd, &tmp->line)) > 0)
	{
		if (check_line(tmp->line))
			ft_errors(2);
		tmp->tab = ft_strsplit(tmp->line, ' ');
		tmp->next = (t_rows *)malloc(sizeof(t_rows));
		if (!tmp->next)
			ft_errors(3);
		free(tmp->line);
		tmp = tmp->next;
	}
	tmp->tab = NULL;
	if (ret == -1 || parse_lines(&rows, stp))
		ft_errors(2);
}
