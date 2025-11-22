/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:00:26 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/05/27 14:46:00 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sum;
	int	i;
	int	sign;

	sign = 1;
	sum = 0;
	i = 0;
	while ((nptr[i] == ' ') || ((nptr[i] >= 9) && (nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		sum = ((sum * 10) + (nptr[i] - '0'));
		i++;
	}
	i++;
	return (sum * sign);
}

/*int	main(void)
{
	char	*str1;

	str1 = "----24223999h7";
	printf("%d\n", ft_atoi(str1));
	printf("%d", atoi(str1));
}*/
