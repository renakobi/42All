/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:29:45 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/05/30 21:13:47 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	j = ft_strlen(s1);
	if (!s1)
		return (NULL);
	while (s1[i] && !ft_check(set, s1[i]))
		i++;
	while (j > i && !ft_check(set, s1[j - 1]))
		j--;
	str = (char *)malloc((j - i + 1) * (sizeof(char)));
	if (!str)
		return (NULL);
	while (i < j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}

/*int main() {
    char str1[] = "  Hello, world!";
    char str2[] = "  gAn nrghjing";
    char str3[] = "  No spaces";
	char set[] = {' '};

    printf("Original string 1: \"%s\"\n", str1);
    printf("Trimmed string 1: \"%s\"\n", ft_strtrim(str1, set));

    printf("Original string 2: \"%s\"\n", str2);
    printf("Trimmed string 2: \"%s\"\n", ft_strtrim(str2, set));

    printf("Original string 3: \"%s\"\n", "  No spaces");
    printf("Trimmed string 3: \"%s\"\n", ft_strtrim("  No spaces", set));

    return 0;
}*/