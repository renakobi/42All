/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:41:52 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/09/03 18:38:11 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bit_per_pixel / 8));
	*(unsigned int *)(img->pixel + offset) = color;
}

t_complex	calculate(int x, int y, t_fractal *fractal)
{
	t_complex	c;

	c.r = fractal->x_min + x * (fractal->x_max - fractal->x_min) / (WIDTH - 1);
	c.i = fractal->y_min + y * (fractal->y_max - fractal->y_min) / (LENGTH - 1);
	return (c);
}

static void	handle_pixel(int x, int y, t_fractal *fractal, t_complex c)
{
	int			color;
	int			i;
	t_complex	z;

	i = 0;
	z.i = 0;
	z.r = 0;
	while (i < fractal->iteration)
	{
		z = cmpl_sum(cmpl_square(z), c);
		if ((z.r * z.r) + (z.i * z.i) > fractal->diverge)
		{
			color = (0x0000FF - 0x0FFFFF) * (i) / fractal->diverge + 0x0FFFFF;
			put_pixel(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	put_pixel(x, y, &fractal->img, 0x800080);
}

void	render(t_fractal *fractal)
{
	if (!(ft_strncmp(fractal->name, "Julia", 5)))
		render_julia(fractal);
	else if (!(ft_strncmp(fractal->name, "Mandelbrot", 5)))
		render_mandel(fractal);
}

void	render_mandel(t_fractal *fractal)
{
	int			x;
	int			y;
	t_complex	c;

	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < LENGTH)
		{
			c.r = fractal->x_min + x * (fractal->x_max - fractal->x_min)
				/ (WIDTH - 1);
			c.i = fractal->y_min + y * (fractal->y_max - fractal->y_min)
				/ (LENGTH - 1);
			handle_pixel(x, y, fractal, c);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_init,
		fractal->mlx_window, fractal->img.img, 0, 0);
}
