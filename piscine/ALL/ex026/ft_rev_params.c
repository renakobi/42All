/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:02:08 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/04/29 16:05:29 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i ++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{		
		i = argc - 1;
		while (argv[i] && i > 0)
		{
			ft_putstr(argv[i]);
			write(1, "\n", 1);
			--i;
		}
	}
	return (0);
}
