/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:31:05 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/07/21 18:31:05 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicates(t_stack *a)
{
	t_stack	*current;
	t_stack	*checker;

	if (!a)
		return (0);
	current = a;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->content == checker->content)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	t_stack	*next;

	while (a)
	{
		next = a->next;
		if (next && a->content > next->content)
			return (0);
		a = next;
	}
	return (1);
}

void	append_node(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

size_t	ft_strlen(const char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
	{
		count ++;
	}
	return (count);
}

void	free_all(char **args, t_stack **a)
{
	free_split(args);
	free_stack(a);
}
