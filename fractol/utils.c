/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:42:07 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/09/03 15:09:34 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return (s1[i] - s2[i]);
}

static double	parse_fraction(const char *str, int *i)
{
	double	frac;
	double	res;

	frac = 0.1;
	res = 0;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		res += (str[*i] - '0') * frac;
		frac /= 10;
		(*i)++;
	}
	return (res);
}

float	ft_atof(const char *nptr)
{
	int		i;
	int		sign;
	double	answer;

	i = 0;
	sign = 1;
	answer = 0;
	if (!nptr)
		return (0);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		answer *= 10 + (nptr[i++] - '0');
	if (nptr[i] == '.')
	{
		i++;
		while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
			answer = parse_fraction(nptr, &i);
	}
	return (sign * answer);
}
