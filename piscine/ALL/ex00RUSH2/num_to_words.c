/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:11:31 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/04/27 21:20:01 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	extra25(t_dict *dict, int size, unsigned long long nb)
{
	print_number(dict, size, (nb / 10) * 10);
	ft_putstr(" ");
	print_number(dict, size, nb % 10);
}

static void	print_large(t_dict *dict, int size, unsigned long long nb,
	unsigned long long unit)
{
	if (nb >= unit)
	{
		print_number(dict, size, nb / unit);
		ft_putstr(" ");
		print_single_word(dict, size, unit);
		ft_putstr(" ");
		print_number(dict, size, nb % unit);
	}
}

void	print_number(t_dict *dict, int size, unsigned long long nb)
{
	if (nb == 0)
	{
		print_single_word(dict, size, 0);
		return ;
	}
	if (nb >= 1000000000000000000)
		print_large(dict, size, nb, 1000000000000000000);
	else if (nb >= 1000000000000000)
		print_large(dict, size, nb, 1000000000000000);
	else if (nb >= 1000000000000)
		print_large(dict, size, nb, 1000000000000);
	else if (nb >= 1000000000)
		print_large(dict, size, nb, 1000000000);
	else if (nb >= 1000000)
		print_large(dict, size, nb, 1000000);
	else if (nb >= 1000)
		print_large(dict, size, nb, 1000);
	else if (nb >= 100)
		print_large(dict, size, nb, 100);
	else if (get_word(dict, size, nb))
		print_single_word(dict, size, nb);
	else
	{
		extra25(dict, size, nb);
	}
}
