/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:34:58 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/04/27 20:35:31 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_single_word(t_dict *dict, int size, unsigned long long nb)
{
	char	*word;

	word = get_word(dict, size, nb);
	if (word)
		ft_putstr(word);
}
