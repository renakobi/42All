/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:55:54 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/05/25 18:11:35 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int a)
{
	if ((a >= 0 && a <= 127))
	{
		return (1);
	}
	else
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
	printf("%d", ft_isascii('9'));
	printf("%d", ft_isascii('c'));
	printf("%d", ft_isascii('-'));
	printf("%d", ft_isascii(2));
}
*/