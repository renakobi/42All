/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:12:03 by alissa            #+#    #+#             */
/*   Updated: 2025/04/22 10:34:32 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_vis_row_l(int arr[4][4], int row, int inp);
int	check_vis_row_r(int arr[4][4], int row, int inp);
int	check_vis_col_u(int arr[4][4], int col, int inp);
int	check_vis_col_d(int arr[4][4], int col, int inp);

int	check_no_dup_row(int arr[4][4], int row)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = i + 1;
		while (j < 4)
		{
			if (arr[row][i] == arr[row][j] && arr[row][i] != 0)
			{	
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
/*same for the concept of Rush00 a loop to check if any of the columns are empty and if theyre duplicating*/

int	check_dup_col(int arr[4][4], int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = i + 1;
		while (j < 4)
		{
			if (arr[i][col] == arr[j][col] && arr[i][col] != 0)
			{	
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_all(int arr[4][4], int inp[16], int row, int col)
{
	if (check_no_dup_row(arr, row) || check_no_dup_col(arr, col))
		return (0);
	if (col == 3)
	{
		if (!check_vis_row_l(arr, row, inp[row + 8]) //positionnnnnnn
			||!check_vis_row_r(arr, row, inp[row + 12]))
			return (0);
	}
	if (row == 3)
	{
		if (!check_vis_col_u(arr, col, inp[col])
			||!check_vis_col_d(arr, col, inp[col + 4]))
			return (0);
	}
	return (1);
}
//calling the check functions and using them to continuously check all throughout 
int	solvemap(int arr[4][4], int row, int col, int inp[16])
{
	int	nb;

	nb = 1;
	if (col == 4)
		return (solvemap(arr, row + 1, 0, inp));
		//first do rows
	if (row == 4)
		return (1);
	while (nb <= 4)
	{
		arr[row][col] = nb;
		if (check_all(arr, inp, row, col)
			&& solvemap(arr, row, col + 1, inp))
			//then do columns and exit when done
			return (1);
		arr[row][col] = 0;
		nb++;
	}
	return (0);
}
//using recursionnnnn index by index