/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:33:09 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/07/21 17:33:09 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *b)
{
	int		max;
	t_stack	*tmp;

	max = b->index;
	tmp = b;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	find_index_position(t_stack *b, int index)
{
	int	pos;

	pos = 0;
	while (b)
	{
		if (b->index == index)
			return (pos);
		b = b->next;
		pos++;
	}
	return (-1);
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	size;
	int	pos;
	int	max;

	while (*b)
	{
		max = find_max_index(*b);
		size = stack_size(*b);
		pos = find_index_position(*b, max);
		if (pos <= size / 2)
		{
			while ((*b)->index != max)
				rotate_a(b, 'b');
		}
		else
		{
			while ((*b)->index != max)
				r_rotate_a(b, 'b');
		}
		push_a(a, b, 'a');
	}
}
