/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:13:09 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/07/02 15:06:05 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_stack **a, t_stack **b)
{
	t_stack	*curr;
	t_stack	*curr_b;
	t_stack	*post;
	t_stack	*post_b;

	if (!((*a)->next) || !a || !*a || !(*b)->next || !*b || !b)
		return ;
	curr = *a;
	curr_b = *b;
	post = (*a)->next;
	post_b = (*b)->next;
	curr->next = post->next;
	post->next = curr;
	curr_b->next = post_b->next;
	post_b->next = curr_b;
	*a = post;
	*b = post_b;
	write(1, "ss\n", 3);
}

void	rotate_both(t_stack **a, t_stack **b)
{
	t_stack	*curr;
	t_stack	*curr_b;
	t_stack	*tmp;
	t_stack	*tmp_b;

	if (!((*a)->next) || !a || !*a || !(*b)->next || !*b || !b)
		return ;
	curr = *a;
	curr_b = *b;
	tmp = *a;
	tmp_b = *b;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp_b->next)
		tmp_b = tmp_b->next;
	*a = curr->next;
	*b = curr_b->next;
	curr->next = NULL;
	curr_b->next = NULL;
	tmp->next = curr;
	tmp_b->next = curr_b;
	write(1, "rr\n", 3);
}
