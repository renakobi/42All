/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:11:34 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/04/27 21:07:48 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

unsigned long long	ft_atoull(char *str)
{
	unsigned long long	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
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

static int	parse_and_print(char *dictname, char *number)
{
	t_dict				*dict;
	int					dict_size;
	unsigned long long	nb;

	if (!parse_dict(dictname, &dict, &dict_size))
		return (ft_puterror("Dict Error\n"), 1);
	if (!is_valid_number(number))
		return (ft_puterror("Error\n"), free_dict(dict, dict_size), 1);
	nb = ft_atoull(number);
	print_number(dict, dict_size, nb);
	ft_putstr("\n");
	free_dict(dict, dict_size);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		return (parse_and_print("numbers.dict", argv[1]));
	else if (argc == 3)
		return (parse_and_print(argv[1], argv[2]));
	ft_puterror("Error\n");
	return (1);
}
