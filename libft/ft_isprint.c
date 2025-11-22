/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:59:13 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/05/25 18:13:28 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int a)
{
	if ((a > 31 && a < 127))
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
	printf("%d", ft_isprint('9'));
	printf("%d", ft_isprint('c'));
	printf("%d", ft_isprint('-'));
	printf("%d", ft_isprint('\n'));
}
*/