/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:05:56 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/05/31 14:56:32 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, int n)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = c ;
		i++;
	}
	return (str);
}

/*#include <string.h>
 check(i == 42 && tab[42] == 0); showLeaks()
int main()
{
    char str[50] = "42 Beirut school libft etc etc.grgr";
    printf("\nBefore memset(): %s\n", str);
    memset(str + 13, 'o', 8*sizeof(char));
    printf("After memset():  %s", str);
    return 0;
}*/