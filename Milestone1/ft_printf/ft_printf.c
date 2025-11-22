/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:10:12 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/06/04 14:43:45 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			if (is_specifier(string[i + 1]))
				count += get_arg(args, string, i + 1);
			else if (string[i + 1] == ' ')
				count += ft_putchar_fd('%', 1);
		}
		else
		{
			count += putchar(string[i]);
			i++;
		}
	}
	return (count);
}
