/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:52:11 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/05/25 18:12:30 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int a)
{
	if ((a >= 48 && a <= 57))
		return (1);
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
	printf("%d", ft_isdigit('9'));
	printf("%d", ft_isdigit('c'));
	printf("%d", ft_isdigit('-'));
}
*/