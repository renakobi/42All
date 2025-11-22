/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:11:01 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/05/27 14:30:00 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big || !little)
		return (NULL);
	if (*little == '\0')
		return ((char *) big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i + j] == little[j])
		{
			while (big[i + j] && little[j] && i + j < len
				&& big[i + j] == little[j])
			{
				j++;
				if (!little[j])
					return ((char *)&big[i + j - ft_strlen(little)]);
			}
		}
		i ++;
	}
	return (NULL);
}

/*int main ()
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	printf("%s", ft_strnstr(haystack,"aaabc", 5));
}*/