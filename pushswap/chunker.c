/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:36:23 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/07/21 17:36:23 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_params(int size, int *count, int *chunk_size)
{
	if (size <= 100)
		*count = 5;
	else if (size <= 500)
		*count = 12;
	else
		*count = ((size - 500) / 25) + 20;
	if (size % *count == 0)
		*chunk_size = size / *count;
	else
		*chunk_size = (size / *count) + 1;
}

int	get_closest_top(t_stack *a, int start, int end)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->index >= start && a->index < end)
			return (i);
		a = a->next;
		i++;
	}
	return (i);
}

int	get_closest_bottom(t_stack *a, int start, int end)
{
	int		pos;
	int		last_match;
	t_stack	*tmp;

	pos = 0;
	last_match = -1;
	tmp = a;
	while (tmp)
	{
		if (tmp->index >= start && tmp->index < end)
			last_match = pos;
		tmp = tmp->next;
		pos++;
	}
	if (last_match == -1)
		return (pos);
	return (pos - last_match);
}
