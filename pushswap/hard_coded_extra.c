/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coded.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:16:23 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/07/13 17:33:53 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lowest(t_stack *a)
{
	int	min;

	if (!a)
		return (-1);
	min = a->index;
	while (a)
	{
		if (a->index < min)
			min = a->index;
		a = a->next;
	}
	return (min);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		size;
	int		pos;
	int		min;

	min = find_lowest(*a);
	pos = 0;
	temp = (*a)->next;
	while (temp && temp->index != min)
	{
		pos++;
		temp = temp->next;
	}
	size = stack_size(*a);
	while ((*a)->index != min)
	{
		if (pos <= size / 2)
			rotate_a(a, 'a');
		else
			r_rotate_a(a, 'a');
	}
	push_a(b, a, 'b');
}
