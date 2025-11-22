/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:41:14 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/08/17 18:40:37 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scaler(double num1, double new_min,
	double new_max, double old_max)
{
	return ((new_max - new_min) * (num1 - MIN) / (old_max - MIN) + new_min);
}

t_complex	cmpl_sum(t_complex z1, t_complex z2)
{
	t_complex	sum;

	sum.r = z1.r + z2.r;
	sum.i = z1.i + z2.i;
	return (sum);
}

t_complex	cmpl_square(t_complex z)
{
	t_complex	mult;

	mult.r = (z.r * z.r) - (z.i * z.i);
	mult.i = 2 * z.r * z.i;
	return (mult);
}
