/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:14:27 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/04/22 11:42:01 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i ++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j ++;
	}
	dest[i + j] = '\0';
	return (dest);
}
