/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:11:29 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/05/27 15:44:58 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;
	long	length;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(length + 1 * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i ++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j ++;
	}
	str[i + j] = '\0';
	return (str);
}

/*int main (void)
{
	const char *s1 = "Hello, ";
	const char *s2 = "World      !";
	char *joined = ft_strjoin(s1, s2);
	if(joined != NULL)
	{
		printf("joined: %s", joined);
		free(joined);
	}
	else
		printf("fail");
	return (0);
}*/