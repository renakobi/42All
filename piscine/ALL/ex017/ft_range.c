/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:26:50 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/04/30 21:29:08 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		i;
	char	*temp;
	int		length;

	if (min >= max)
		return (0);
	temp = (int *)malloc((max - min) * (sizeof(int)));
	if (!temp)
		return (NULL);
	i = 0;
	while (min < max)
	{
		temp[i] = min;
		min ++;
		i ++;
	}
	return (temp);
}
