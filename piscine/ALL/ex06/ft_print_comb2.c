/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:32:10 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/04/19 18:20:39 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(int a, int b)
{
	char	x;

	x = a / 10 + '0' ;
	write (1, &x, 1);
	x = a % 10 + '0';
	write (1, &x, 1);
	write (1, " ", 1);
	x = b / 10 + '0' ;
	write (1, &x, 1);
	x = b % 10 + '0';
	write (1, &x, 1);
	if (a != 98 || b != 99)
		write (1, ",", 1);
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;

	i = 0;
	while (i < 99)
	{
		j = i +1;
		while (j <= 99)
		{	
			print_char (i, j);
			j ++;
		}
		i ++;
	}
}
