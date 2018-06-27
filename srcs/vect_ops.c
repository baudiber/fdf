/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 17:31:31 by baudiber          #+#    #+#             */
/*   Updated: 2018/06/26 17:32:51 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_hpt	mult_4x4mat_hpt(t_mat4x4 mat, t_hpt p)
{
	t_hpt	res;

	res.x = mat.m[0][0] * p.x + mat.m[0][1] * p.y + mat.m[0][2] * \
			p.z + mat.m[0][3] * p.w;
	res.y = mat.m[1][0] * p.x + mat.m[1][1] * p.y + mat.m[1][2] * \
			p.z + mat.m[1][3] * p.w;
	res.z = mat.m[2][0] * p.x + mat.m[2][1] * p.y + mat.m[2][2] * \
			p.z + mat.m[2][3] * p.w;
	res.w = mat.m[3][0] * p.x + mat.m[3][1] * p.y + mat.m[3][2] * p.z + mat.m[3][3] * p.w;
	return (res);
}

t_hpt		hpt(float x, float y, float z, float w)
{
	t_hpt	pt;

	pt.x = x;
	pt.y = y;
	pt.z = z;
	pt.w = w;
	return (pt);
}

t_mat4x4	id_mat(void)
{
	t_mat4x4	mat;

	ft_bzero(&mat, sizeof(t_mat4x4));
	mat.m[0][0] = 1.0;
	mat.m[1][1] = 1.0;
	mat.m[2][2] = 1.0;
	mat.m[3][3] = 1.0;
	return (mat);
}

t_mat4x4	scale_mat(t_hpt scale)
{
	t_mat4x4	mat;
	
	mat = id_mat();
	mat.m[0][0] = scale.x;	
	mat.m[1][1] = scale.y;	
	mat.m[2][2] = scale.z;	
	mat.m[3][3] = 1.0;
	return (mat);
}

t_mat4x4	mult_4x4mat(t_mat4x4 m1, t_mat4x4 m2)
{
	int			i;
	int			j;
	t_mat4x4	res;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res.m[i][j] = m1.m[i][0] * m2.m[0][j] + \
						  m1.m[i][1] * m2.m[1][j] + \
						  m1.m[i][2] * m2.m[2][j] + \
						  m1.m[i][3] * m2.m[3][j];
			j++;
		}
		i++;
	}
	return (res);
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
