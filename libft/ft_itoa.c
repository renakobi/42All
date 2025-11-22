/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:04:30 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/05/30 21:02:50 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_nbrsize(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_tochar(char *str, long nb, long length)
{
	while (nb > 0)
	{
		str[length] = (nb % 10) + 48;
		nb = nb / 10;
		length--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;

	nb = n;
	str = (char *)malloc((ft_nbrsize(nb) + 1) * sizeof(char));
	i = ft_nbrsize(n);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	str = ft_tochar(str, nb, i);
	return (str);
}

// int	main(void)
// {
// 	printf("%s", itoa(-2147483648));
// }