/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:50:45 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/07/21 17:50:45 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

static int	is_not_empty(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!is_not_empty(str))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res * sign);
}

int	fill_stack(t_stack **a, int ac, char **av)
{
	t_stack	*node;
	long	n;
	int		i;

	i = 0;
	while (i < ac)
	{
		if (!is_valid_number(av[i]))
			return (0);
		n = ft_atol(av[i]);
		if (n > 2147483647 || n < -2147483648)
			return (0);
		node = new_node((int)n);
		if (!node)
			return (0);
		append_node(a, node);
		i++;
	}
	return (1);
}
