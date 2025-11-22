/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:48:01 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/07/02 15:04:27 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a, t_stack **b, char c)
{
	t_stack	*top;

	if (!b || !*b)
		return ;
	top = *b;
	*b = (*b)->next;
	top->next = *a;
	*a = top;
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

void	swap_a(t_stack **a, char c)
{
	t_stack	*curr;
	t_stack	*post;

	if (!((*a)->next) || !a || !*a)
		return ;
	curr = *a;
	post = (*a)->next;
	curr->next = post->next;
	post->next = curr;
	*a = post;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	rotate_a(t_stack **a, char c)
{
	t_stack	*curr;
	t_stack	*tmp;

	curr = *a;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	*a = curr->next;
	curr->next = NULL;
	tmp->next = curr;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	r_rotate_a(t_stack **a, char c)
{
	t_stack	*curr;
	t_stack	*tmp;
	t_stack	*pre_tmp;

	curr = *a;
	pre_tmp = *a;
	tmp = (*a)->next;
	while (tmp->next)
	{
		pre_tmp = tmp;
		tmp = tmp->next;
	}
	*a = tmp;
	pre_tmp->next = NULL;
	(*a)->next = curr;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	else
		return ;
}
