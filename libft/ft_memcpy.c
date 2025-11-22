/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:44:05 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/05/27 13:32:38 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (!src && !dest)
		return (NULL);
	i = 0;
	if (dest != src)
	{
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	return (dest);
}
//check(rtn == dest && dest[0] == 'A'); showLeaks();
//    char src[] = {0, 0};
//  ft_memcpy(dest, src, 2);
//     int i = 0;

/*#include <string.h>

int main() {
    int a = 20;
    int b = 10;
    
    printf("Value of b before calling memcpy: %d\n", b);
    ft_memcpy(&b, &a, sizeof(int)); 
    printf("Value of b after calling memcpy: %d\n", b);
    return 0;
}*/