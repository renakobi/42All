/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:10:14 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/07/13 15:11:47 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack *a, int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (a)
	{
		arr[i++] = a->content;
		a = a->next;
	}
	return (arr);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	var;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				var = tab[i];
				tab[i] = tab[j];
				tab[j] = var;
			}
			j++;
		}
		i++;
	}
}

void	indexing(int *r, t_stack *a, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (a->content == r[i])
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}

void	sort_stack(t_stack *a, int size)
{
	int	*arr;

	arr = stack_to_array(a, size);
	if (!arr)
		return ;
	ft_sort_int_tab(arr, size);
	indexing(arr, a, size);
	free(arr);
}

int	stack_size(t_stack *a)
{
	t_stack	*temp;
	int		count;

	temp = a;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
