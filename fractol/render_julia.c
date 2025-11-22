/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:07:06 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/09/03 18:25:52 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_jpixel(int x, int y, t_fractal *fractal, t_complex c)
{
	int			color;
	int			i;
	t_complex	z;

	i = 0;
	z = calculate(x, y, fractal);
	while (i < fractal->iteration)
	{
		z = cmpl_sum(cmpl_square(z), c);
		if ((z.r * z.r) + (z.i * z.i) > fractal->diverge)
		{
			color = (0x0F0022 - 0xFF00FF) * (i) / fractal->diverge + 0xF02FFFF;
			put_pixel(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
}

void	render_julia(t_fractal *fractal)
{
	int			x;
	int			y;
	t_complex	c;

	c.i = fractal->c.i;
	c.r = fractal->c.r;
	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < LENGTH)
		{
			handle_jpixel(x, y, fractal, c);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_init,
		fractal->mlx_window, fractal->img.img, 0, 0);
}
