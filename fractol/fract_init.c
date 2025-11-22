/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:40:25 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/10/23 18:52:20 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(t_fractal *fr)
{
	perror("Malloc error");
	free(fr->mlx_init);
	free(fr->mlx_window);
	exit(1);
}

void	data_init(t_fractal *fractal)
{
	fractal->diverge = 4;
	fractal->iteration = 40;
	fractal->color = 0x0000FF;
	fractal->x_min = -2;
	fractal->x_max = 1;
	fractal->y_min = -1.5;
	fractal->y_max = 1.5;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_init = mlx_init();
	if (fractal->mlx_init == NULL)
		malloc_error(fractal);
	fractal->mlx_window = mlx_new_window(fractal->mlx_init,
			WIDTH, LENGTH, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_init);
		free(fractal->mlx_init);
		malloc_error(fractal);
	}
	fractal->img.img = mlx_new_image(fractal->mlx_init, WIDTH, LENGTH);
	if (fractal->img.img == NULL)
	{
		mlx_destroy_window(fractal->mlx_init, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_init);
		free(fractal->mlx_init);
		write(1, "ERROR", 5);
		exit(1);
	}
	fractal->img.pixel = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bit_per_pixel,
			&fractal->img.line_len, &fractal->img.endian);
}
