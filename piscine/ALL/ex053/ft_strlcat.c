/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:06:17 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/04/27 18:48:11 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_d;
	unsigned int	len_s;
	unsigned int	i;

	i = 0;
	len_d = 0;
	len_s = 0;
	while (dest[len_d] && len_d < size)
	{
		len_d++;
	}
	while (src[len_s])
		len_s++;
	if (len_d >= size)
		return (size + len_s);
	while (src[i] && (len_d + i) < size - 1)
	{
		dest[len_d + i] = src[i];
		i ++;
	}
	dest[len_d + i] = '\0';
	return (len_d + len_s);
}
