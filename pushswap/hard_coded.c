/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:11:45 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/07/13 17:42:40 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_2(t_stack **a)
{
	t_stack	*temp;

	temp = (*a)->next;
	if ((*a)->index > temp->index)
	{
		swap_a(a, 'a');
	}
}

void	init(t_stack *a, t_stack **first, t_stack **second, t_stack **third)
{
	*first = a;
	if (a != NULL)
		*second = a->next;
	else
		*second = NULL;
	if (second != NULL)
		*third = (*second)->next;
	else
		*third = NULL;
}

void	count_3(t_stack **a)
{
	t_stack	*f;
	t_stack	*s;
	t_stack	*t;

	init(*a, &f, &s, &t);
	if (f->index > s->index && s->index < t->index && f->index < t->index)
		swap_a(a, 'a');
	else if (f->index > s->index && s->index > t->index)
	{
		swap_a(a, 'a');
		r_rotate_a(a, 'a');
	}
	else if (f->index > s->index && s->index < t->index && f->index > t->index)
		rotate_a(a, 'a');
	else if (f->index < s->index && s->index > t->index && f->index < t->index)
	{
		swap_a(a, 'a');
		rotate_a(a, 'a');
	}
	else
	{
		r_rotate_a(a, 'a');
		count_2(a);
	}
}

void	five_andfour(t_stack **a, t_stack **b)
{
	t_stack	*ind;

	while (stack_size(*a) > 3)
		push_to_b(a, b);
	count_3(a);
	push_a(a, b, 'a');
	push_a(a, b, 'a');
	ind = *a;
	if ((*a)->index < ind->index)
		swap_a(a, 'a');
}
