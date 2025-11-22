/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:52:39 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/05/25 18:08:29 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int a)
{
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122) || (a >= 48 && a <= 57))
	{
		return (1);
	}
	return (0);
}

/*int	main(void)
{
	int		a;
	char	*c;
	char	*d;

	a = 23423;
	c = "22345";
	d = "234d";
	printf("%d", ft_isalnum('9'));
	printf("%d", ft_isalnum('c'));
	printf("%d", ft_isalnum('-'));
}
*/