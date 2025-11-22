/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:41:00 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/07/21 17:41:00 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_and_init(t_stack **a, int argc, char **argv)
{
	if (!fill_stack(a, argc, argv))
	{
		free_stack(a);
		write(2, "Error\n", 6);
		return (0);
	}
	if (has_duplicates(*a))
	{
		free_stack(a);
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

/*static int	check_args_and_init(t_stack **a, char **args)
{
	int	count;

	count = 0;
	while (args[count])
	{
		if (!is_valid_number(args[count]))
		{
			free_split(args);
			write(2, "Error\n", 6);
			return (0);
		}
		count++;
	}
	if (!check_and_init(a, count, args))
	{
		free_all(args, a);
		return (0);
	}
	return (1);
}*/
int	prepare_stack(t_stack **a, int argc, char **argv)
{
	char	**args;
	int		count;

	if (argc == 1)
		return (write(2, "Error\n", 6), 0);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !*args)
			return (write(2, "Error\n", 6), free_split(args), 0);
		count = 0;
		while (args[count])
			if (!is_valid_number(args[count++]))
				return (free_split(args), write(2, "Error\n", 6), 0);
		if (!check_and_init(a, count, args))
			return (free_split(args), 0);
		return (free_split(args), 1);
	}
	return (check_and_init(a, argc - 1, argv + 1));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!prepare_stack(&a, argc, argv))
		return (1);
	sort_stack(a, stack_size(a));
	if (!is_sorted(a))
	{
		if (stack_size(a) == 2)
			count_2(&a);
		else if (stack_size(a) <= 5)
			five_andfour(&a, &b);
		else
			chunk_sort(&a, &b, stack_size(a));
	}
	free_stack(&a);
	return (0);
}
