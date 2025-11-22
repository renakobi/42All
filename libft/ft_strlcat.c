/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:46:30 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/05/24 23:15:31 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	len_d;
	unsigned int	len_s;
	unsigned int	i;

	i = 0;
	len_d = 0;
	len_s = 0;
	while (dst[len_d] && len_d < size)
	{
		len_d++;
	}
	while (src[len_s])
		len_s++;
	if (len_d >= size)
		return (size + len_s);
	while (src[i] && (len_d + i) < size - 1)
	{
		dst[len_d + i] = src[i];
		i ++;
	}
	dst[len_d + i] = '\0';
	return (len_d + len_s);
}
