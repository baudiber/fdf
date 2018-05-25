/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect&quat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 00:12:41 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/23 01:11:28 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_hpt	cross_product(t_hpt v0, t_hpt v1)
{
	t_hpt	res;

	res.x = v0.y * v1.z - v0.z * v1.y;
	res.y = v0.z * v1.x - v0.x * v1.z;
	res.z = v0.x * v1.y - v0.y * v1.x;
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

/*
void	get_matrix(t_quat q, t_setup *stp)
{
	stp->mat[0][0] = 1 - 2 * ((q.vect.y * q.vect.y) +(q.vect.z * q.vect.z));
	stp->mat[0][1] = 2 * ((q.vect.x * q.vect.y) - (q.vect.z * q.w));
	stp->mat[0][2] = 2 * ((q.vect.x * q.vect.z) + (q.vect.y * q.w));
	stp->mat[1][0] = 2 * ((q.vect.x * q.vect.y) + (q.vect.z * q.w));
	stp->mat[1][1] = 1 - 2 * ((q.vect.x * q.vect.x) + (q.vect.z * q.vect.z));
	stp->mat[1][2] = 2 * ((q.vect.y * q.vect.z) - (q.vect.x * q.w));
	stp->mat[2][0] = 2 * ((q.vect.x * q.vect.z) - (q.vect.y * q.w));
	stp->mat[2][1] = 2 * ((q.vect.y * q.vect.z) + (q.vect.x * q.w));
	stp->mat[2][2] = 1 - 2 * ((q.vect.x * q.vect.x) + (q.vect.y * q.vect.y));
}

double	dot_product(t_vect v0, t_vect v1)
{
	return (v0.x * v1.x + v0.y * v1.y + v0.z * v1.z);
}


t_vect	add_vects(t_vect a, t_vect b, t_vect c)
{
	t_vect	res;

	res.x = a.x + b.x + c.x;
	res.y = a.y + b.y + c.y;
	res.z = a.z + b.z + c.z;
	return (res);
}



t_quat	quaternion_multiplicator(t_quat q0, t_quat q1)
{
	t_quat	res;

	res.w = q0.w  * q1.w - dot_product(q0.vect, q1.vect);
	res.vect = add_vects(scale_vect(q0.w, q1.vect), scale_vect(q1.w, q0.vect), cross_product(q0.vect, q1.vect));
	//add normalize?
	res.vect = normalize_vect(res.vect);
	return (res);
}
*/
