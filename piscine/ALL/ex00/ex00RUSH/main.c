/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:14:18 by alissa            #+#    #+#             */
/*   Updated: 2025/04/22 10:31:40 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int		solvemap(int arr[4][4], int row, int col, int inp[16]);
int		ft_valid(char *str);
int		*ft_toarray(char *str, int arr[16]);
void	ft_put2d(int arr[4][4]);
void	ft_initialize(int arr[4][4]);

int	main(int argc, char *argv[])
{
	int	map[4][4];
	int	inp[16];

	if (argc != 2 || !ft_valid(argv[1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	ft_toarray(argv[1], inp);
	ft_initialize(map);
	if (solvemap(map, 0, 0, inp))
		ft_put2d(map);
	else
		write(1, "Error\n", 6);
	return (0);
}
