/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect&quat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baudiber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 00:12:41 by baudiber          #+#    #+#             */
/*   Updated: 2018/05/08 00:13:50 by baudiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_vect	add_vects(t_vect a, t_vect b, t_vect c)
{
	t_vect res;

	res.x = a.x + b.x + c.x;
	res.y = a.y + b.y + c.y;
	res.z = a.z + b.z + c.z;
	return (res);
}

t_quat	quaternion_multiplicator(t_quat q0, t_quat q1)
{
	t_quat	res;

	res.w = q0.a  * q1.a - dot_product(q0.vect, q1.vect);
	res.vect = scale_vect(q0.a * q1.vect) + scale_vect(q1.a * q0.vect) + cross_product(q0.vect, q1.vect);
	return (res);
}
