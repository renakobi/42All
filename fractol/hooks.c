/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 20:21:46 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/09/03 18:14:45 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractal *fr)
{
	double	zoom_factor;
	double	cx;
	double	cy;

	if (button == 4)
		zoom_factor = 0.9;
	else if (button == 5)
		zoom_factor = 1.1;
	else
		return (0);
	cx = fr->x_min + (x / (double)WIDTH)
		* (fr->x_max - fr->x_min);
	cy = fr->y_min + (y / (double)LENGTH)
		* (fr->y_max - fr->y_min);
	fr->x_min = cx + (fr->x_min - cx) * zoom_factor;
	fr->x_max = cx + (fr->x_max - cx) * zoom_factor;
	fr->y_min = cy + (fr->y_min - cy) * zoom_factor;
	fr->y_max = cy + (fr->y_max - cy) * zoom_factor;
	render(fr);
	return (0);
}

static void	x_key(t_fractal *fractal, double dx, int sign)
{
	fractal->x_min += dx * sign;
	fractal->x_max += dx * sign;
}

static void	y_key(t_fractal *fractal, double dy, int sign)
{
	fractal->y_min += dy * sign;
	fractal->y_max += dy * sign;
}

int	key_hook(int keycode, t_fractal *fr)
{
	double	dx;
	double	dy;

	dx = (fr->x_max - fr->x_min) * 0.05;
	dy = (fr->y_max - fr->y_min) * 0.05;
	if (keycode == 65363 || keycode == 100)
		x_key(fr, dx, -1);
	if (keycode == 65361 || keycode == 97)
		x_key(fr, dx, 1);
	if (keycode == 65364 || keycode == 115)
		y_key(fr, dy, -1);
	if (keycode == 65362 || keycode == 119)
		y_key(fr, dy, 1);
	if (keycode == 65307)
		close_window(fr);
	render(fr);
	return (0);
}
