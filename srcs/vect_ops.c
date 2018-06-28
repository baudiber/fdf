/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 17:31:31 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/28 23:59:12 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_hpt	hpt(float x, float y, float z, float w)
{
	t_hpt	pt;

	pt.x = x;
	pt.y = y;
	pt.z = z;
	pt.w = w;
	return (pt);
}

t_hpt	sub_vects(t_hpt a, t_hpt b)
{
	t_hpt	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	res.w = a.w - b.w;
	return (res);
}

t_hpt	cross_product(t_hpt a, t_hpt b)
{
	t_hpt	res;

	res.x = a.y * b.w - b.y * a.z;
	res.y = a.z * b.x - b.z * a.x;
	res.z = a.x * b.y - b.x * a.y;
	return (res);
}

t_hpt	conjugate(t_hpt v)
{
	t_hpt	res;

	res.w = v.w;
	res.x = -v.x;
	res.y = -v.y;
	res.z = -v.z;
	return (res);
}

t_hpt	normalize_vect(t_hpt v)
{
	t_hpt	res;
	float	len;

	len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (len > 0)
	{
		res.x = v.x / len;
		res.y = v.y / len;
		res.z = v.z / len;
		return (res);
	}
	return (v);
}
