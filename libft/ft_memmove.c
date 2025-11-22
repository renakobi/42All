/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:12:24 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/06/04 14:56:21 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sc;
	size_t			i;

	ds = (unsigned char *)dest;
	sc = (unsigned char *)src;
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			ds[i - 1] = sc[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			ds[i] = sc[i];
			i++;
		}
	}
	return (dest);
}

/*#include <string.h>
int main()
{
	 char dest_str[] = "oldstring";
   const char src_str[]  = "newstring";
   printf("Before memmove dest = %s, src = %s\n", dest_str, src_str);
   memmove(dest_str, src_str, 9);
   printf("After memmove dest = %s, src = %s\n", dest_str, src_str);
   return(0);
}*/