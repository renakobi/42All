/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:29:43 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/05/27 10:10:35 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		str[i] = '\0';
		i++;
		n--;
	}
}

/*int	main(void)
{
	int		v[10];

	for (int i = 0; i < 10; ++i)
		v[i] = 42;
	for (int i = 0; i < 10; ++i)
		printf("%d", v[i]);
	puts("");
	ft_bzero(v, 40);
	for (int i = 0; i < 10; ++i)
		printf("%d", v[i]);
}
*/