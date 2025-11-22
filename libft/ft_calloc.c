/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:54:10 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/05/27 12:27:56 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;

	if (nmemb != 0 && size > 2147483647 / nmemb)
		return (0);
	temp = malloc(size * nmemb);
	if (temp == NULL)
		return (NULL);
	ft_bzero(temp, size * nmemb);
	return (temp);
}
