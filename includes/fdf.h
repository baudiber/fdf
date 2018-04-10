/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:18:24 by baudiber          #+#    #+#             */
/*   Updated: 2018/04/10 19:03:07 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
# define _FDF_H_

# include "mlx.h"
# include "libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
	int			color;
}				t_point;

typedef struct	s_rows
{
	int				ptnb;
	t_point			*point;
	struct s_rows	*next;
}				t_rows;

typedef struct	s_setup
{
	int			ptnb;
	int			ynb;
	int			xnb;
	t_rows		*start;
	t_rows		*rows;
}				t_setup;
#endif
