/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:07:32 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/05/31 22:13:53 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str1;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	i = 0;
	str1 = (char *) malloc((len + 1) * sizeof(char));
	if (!str1)
		return (NULL);
	while (s[i] && i < len)
	{
		str1[i] = s[start];
		i++;
		start++;
	}
	str1[i] = '\0';
	return (str1);
}

/*#include <string.h>

int main() {
    char s[] = "Hello, world!";
  	int pos = 7, l = 5;
    char ss[20];
    strncpy(ss, s + 7, 5);
    ss[5] = '\0';
    printf("%s", ft_substr("tripouille", 1, 4));
    return 0;
}*/