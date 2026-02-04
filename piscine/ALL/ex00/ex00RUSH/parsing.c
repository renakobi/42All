/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alissa <alissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:52:13 by alissa            #+#    #+#             */
/*   Updated: 2025/04/20 18:14:00 by alissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 31)
		return (0);
	i = 0;
	while (i < 31)
	{
		if (i % 2 == 0)
		{
			if (!(str[i] >= '1' && str[i] <= '4'))
				return (0);
		}
		else
		{
			if (!(str[i] == ' '))
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	*ft_toarray(char *str, int arr[16])
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
			arr[j++] = str[i] - '0';
		i++;
	}
	return (arr);
}

void	ft_put2d(int arr[4][4])
{
	int		i;
	int		j;
	char	ch;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ch = arr[i][j] + '0';
			write(1, &ch, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

void	ft_initialize(int arr[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
}
