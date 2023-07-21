/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:40:48 by arasal            #+#    #+#             */
/*   Updated: 2022/07/20 00:43:13 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	add(t_complex z, t_complex c)
{
	t_complex	r;

	r.x = z.x + c.x;
	r.y = z.y + c.y;
	return (r);
}

t_complex	square(t_complex z)
{
	t_complex	r;

	r.x = (z.x * z.x) - (z.y * z.y);
	r.y = 2 * z.x * z.y;
	return (r);
}

t_complex	cube(t_complex z)
{
	t_complex	r;

	r.x = (z.x * z.x * z.x) - (3 * z.x * z.y * z.y);
	r.y = (3 * z.x * z.x * z.y) - (z.y * z.y * z.y);
	return (r);
}

t_complex	divide(t_complex z1, t_complex z2)
{
	t_complex	r;

	r.x = (z1.x * z2.x + z1.y * z2.y) / (z2.x * z2.x + z2.y * z2.y);
	r.y = (z1.y * z2.x - z1.x * z2.y) / (z2.x * z2.x + z2.y * z2.y);
	return (r);
}

t_complex	multiply(t_complex z, double c)
{
	t_complex	r;

	r.x = z.x * c;
	r.y = z.y * c;
	return (r);
}
