/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:41:04 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/09/03 18:40:26 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render_hook(void *param)
{
	t_fractal	*fractal;

	fractal = param;
	render(fractal);
	return (0);
}

static void	clean_exit(int exit_code, t_fractal *fractal)
{
	if (fractal->img.img)
		mlx_destroy_image(fractal->mlx_init, fractal->img.img);
	if (fractal->mlx_window && fractal->mlx_init)
		mlx_destroy_window(fractal->mlx_init, fractal->mlx_window);
	if (fractal->mlx_init)
	{
		mlx_loop_end(fractal->mlx_init);
		mlx_destroy_display(fractal->mlx_init);
		free(fractal->mlx_init);
	}
	exit(exit_code);
}

/*int	close_window(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_init, fractal->mlx_window);
	exit(0);
	return (0);
}*/

int	close_window(t_fractal *fractal)
{
	clean_exit(0, fractal);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (((ac == 2) && !(ft_strncmp(av[1], "Mandelbrot", 11)))
		|| ((ac == 4) && !(ft_strncmp(av[1], "Julia", 7))))
	{
		fractal.name = av[1];
		fractal_init(&fractal);
		data_init(&fractal);
		if (!(ft_strncmp(fractal.name, "Julia", 5)))
		{
			fractal.c.r = ft_atof(av[2]);
			fractal.c.i = ft_atof(av[3]);
		}
		mlx_hook(fractal.mlx_window, 4, 1L << 2, mouse_hook, &fractal);
		mlx_hook(fractal.mlx_window, 2, 1L << 0, key_hook, &fractal);
		mlx_hook(fractal.mlx_window, 17, 0, close_window, &fractal);
		render(&fractal);
		mlx_loop(fractal.mlx_init);
	}
	else
	{
		write(1, "ERROR", 5);
		exit(1);
	}
}
