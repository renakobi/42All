/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkvis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alissa <alissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:11:30 by alissa            #+#    #+#             */
/*   Updated: 2025/04/20 15:32:49 by alissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_vis_row_l(int arr[4][4], int row, int inp)
{
	int	max;
	int	vis;
	int	i;

	i = 0;
	vis = 0;
	max = 0;
	while (i < 4)
	{
		if (arr[row][i] > max)
		{
			max = arr[row][i];
			vis++;
		}
		i++;
	}
	return (vis == inp);
}

int	check_vis_row_r(int arr[4][4], int row, int inp)
{
	int	max;
	int	vis;
	int	i;

	i = 3;
	vis = 0;
	max = 0;
	while (i >= 0)
	{
		if (arr[row][i] > max)
		{
			max = arr[row][i];
			vis++;
		}
		i--;
	}
	return (vis == inp);
}

int	check_vis_col_u(int arr[4][4], int col, int inp)
{
	int	max;
	int	vis;
	int	i;

	i = 0;
	vis = 0;
	max = 0;
	while (i < 4)
	{
		if (arr[i][col] > max)
		{
			max = arr[i][col];
			vis++;
		}
		i++;
	}
	return (vis == inp);
}

int	check_vis_col_d(int arr[4][4], int col, int inp)
{
	int	max;
	int	vis;
	int	i;

	i = 3;
	vis = 0;
	max = 0;
	while (i >= 0)
	{
		if (arr[i][col] > max)
		{
			max = arr[i][col];
			vis++;
		}
		i--;
	}
	return (vis == inp);
}
