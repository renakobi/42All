/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:05:42 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/05/27 13:35:48 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return (str1[i] - str2[i]);
}

/*#include <string.h>

int main() {
    int res = 0;
    char s1[10] = "geeks";
    char s2[10] = "greeks";
    res = ft_memcmp(s1, s2, strlen(s1));
    if (res > 0)
        printf("s1 is greater");
    else if (res < 0)
        printf("s2 is greater");
    else
        printf("both are equal");
    return 0;
}*/