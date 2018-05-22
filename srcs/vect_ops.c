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

t_vect	cross_product(t_vect v0, t_vect v1)
{
	t_vect	res;

	res.x = v0.y * v1.z - v0.z * v1.y;
	res.y = v0.z * v1.x - v0.x * v1.z;
	res.z = v0.x * v1.y - v0.y * v1.x;
	return (res);
}

t_vect	scale_vect(double scale, t_vect vect)
{
	t_vect	res;

	res.x = vect.x * scale;
	res.y = vect.y * scale;
	res.z = vect.z * scale;
	return (res);
}

t_vect	sub_vects(t_vect a, t_vect b)
{
	t_vect	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_vect	add_vects(t_vect a, t_vect b, t_vect c)
{
	t_vect	res;

	res.x = a.x + b.x + c.x;
	res.y = a.y + b.y + c.y;
	res.z = a.z + b.z + c.z;
	return (res);
}

t_vect	normalize_vect(t_vect v)
{
	t_vect	res;
	double	len;

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

t_quat	conjugate(t_quat q)
{
	t_quat	res;

	res.w = q.w;
	res.vect.x = -q.vect.x;
	res.vect.y = -q.vect.y;
	res.vect.z = -q.vect.z;
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
