/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:51:42 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/05/25 18:09:56 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int a)
{
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
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
	printf("%d", ft_isalpha('9'));
	printf("%d", ft_isalpha('c'));
	printf("%d", ft_isalpha('-'));
}*/
