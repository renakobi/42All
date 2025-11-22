/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:02:40 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/09/03 18:38:19 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define LENGTH 500
# define WIDTH 500
# define MIN 0
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_img
{
	void	*img;
	char	*pixel;
	int		bit_per_pixel;
	int		endian; //?
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	char		*name;
	void		*mlx_init;
	void		*mlx_window;
	t_img		img;
	double		diverge;
	int			iteration;
	int			color;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	t_complex	c;
}	t_fractal;

void		malloc_error(t_fractal *fr);
void		data_init(t_fractal *fractal);
void		fractal_init(t_fractal *fractal);
double		scaler(double num1, double new_min, double new_max, double old_max);
t_complex	cmpl_sum(t_complex z1, t_complex z2);
t_complex	cmpl_square(t_complex z);
void		render_mandel(t_fractal *fractal);
int			ft_strncmp(char *s1, char *s2, unsigned int n);
int			render_hook(void *param);
int			mouse_hook(int button, int x, int y, t_fractal *fr);
int			key_hook(int keycode, t_fractal *fr);
int			close_window(t_fractal *fractal);
t_complex	calculate(int x, int y, t_fractal *fractal);
void		render_julia(t_fractal *fractal);
void		put_pixel(int x, int y, t_img *img, int color);
void		render(t_fractal *fractal);
float		ft_atof(const char *nptr);

#endif