/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 21:04:13 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/06/04 14:50:31 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_specifier(char c)
{
	const char	*specifiers;
	int			i;

	i = 0;
	specifiers = "cpusdixX";
	while (specifiers[i])
	{
		if (c == specifiers[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_var(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			return (i);
		i++;
	}
	return (0);
}

int	ft_putptr(unsigned long n, char *base)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_putptr(n / 16, base);
	i += ft_putchar_fd(base[n % ft_strlen(base)], 1);
	return (i);
}

int	get_arg(va_list args, const char *str, int length)
{
	if (str[length] == 'c')
		return (ft_putchar_fd(va_arg(args, char), 1));
	else if (str[length] == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (str[length] == 'p')
		return (ft_putptr(va_arg(args, (char *)void * ), "0123456789"));
	else if (str[length] == 'd' || str[length] == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (str[length] == 'u')
		return (ft_putnbr_fd(va_arg(args, unsigned int), 1));
	else if (str[length] == 'X')
		return (ft_put_bs(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (str[length] == 'x')
		return (ft_put_bs(va_arg(args, unsigned int), "0123456789abcdef"));
	return (0);
}

int	ft_put_bs(unsigned int n, char *base)
{
	int	i;

	i = 0;
	if (n >= ft_strlen(base))
		i += ft_put_bs(n / ft_strlen(base), base);
	i += ft_putchar_fd(base[n % ft_strlen(base)], 1);
	return (i);
}
