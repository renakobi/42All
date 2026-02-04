/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:50:38 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/04/30 21:18:21 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*fd;

	i = 0;
	fd = (char *) malloc(ft_strlen(src) + 1 * sizeof(char));
	if (!fd)
		return (NULL);
	while (src[i])
	{
		fd[i] = src[i];
		i++;
	}
	fd[i] = '\0';
	return (fd);
}
