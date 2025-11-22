/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:34:20 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/07/21 17:34:20 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_in_stack(t_stack *a, int start, int end)
{
	while (a)
	{
		if (a->index >= start && a->index < end)
			return (1);
		a = a->next;
	}
	return (0);
}

void	move_chunk_to_b(t_stack **a, t_stack **b, int start, int end)
{
	int	top;
	int	bottom;
	int	size;

	while (chunk_in_stack(*a, start, end))
	{
		size = stack_size(*a);
		top = get_closest_top(*a, start, end);
		bottom = get_closest_bottom(*a, start, end);
		if (top <= size - bottom)
			rotate_top_and_push(a, b, top);
		else
			reverse_and_push(a, b, bottom);
	}
}

void	rotate_top_and_push(t_stack **a, t_stack **b, int top)
{
	while (top > 0)
	{
		rotate_a(a, 'a');
		top--;
	}
	push_a(b, a, 'b');
}

void	reverse_and_push(t_stack **a, t_stack **b, int bottom)
{
	int	i;
	int	size;

	i = 0;
	size = stack_size(*a);
	while (i < size - bottom)
	{
		r_rotate_a(a, 'a');
		i++;
	}
	push_a(b, a, 'b');
}

void	chunk_sort(t_stack **a, t_stack **b, int size)
{
	int	count;
	int	chunk_size;
	int	start;
	int	end;
	int	i;

	chunk_params(size, &count, &chunk_size);
	start = 0;
	i = 0;
	while (i < count)
	{
		end = start + chunk_size;
		move_chunk_to_b(a, b, start, end);
		start = end;
		i++;
	}
	push_back_to_a(a, b);
}
