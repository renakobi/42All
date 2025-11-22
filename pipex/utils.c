/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:48:43 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/09/23 19:03:46 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return (s1[i] - s2[i]);
}

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

size_t	ft_strlen(const char *str)
{
	size_t		count;

	count = 0;
	while (str[count])
	{
		count ++;
	}
	return (count);
}

void	checker(char *path, char **paths, t_pipe pipes, char **temp)
{
	if (!path)
	{
		perror("command not found");
		cleanup_and_exit(NULL, temp, paths, 127);
	}
	if (execve(path, temp, pipes.env) == -1)
	{
		perror("execve failed");
		cleanup_and_exit(path, temp, paths, -1);
	}
}
