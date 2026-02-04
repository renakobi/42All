/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:27:47 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/04/23 15:12:51 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		if ((str[i] >= 'a' && str[i] <= 'z')
			&& (str[i - 1] <= 47 || str[i - 1] >= 58)
			&& (str[i - 1] <= 64 || str[i - 1] >= 91)
			&& (str[i - 1] <= 96 || str[i - 1] >= 123))
		{
			str[i] = str[i] - 32;
		}
		i ++;
	}
	return (str);
}
int main ()
{
	char str[] = "HEkdbdkl KGNRKJG &&nFGNDJN $432O H";
	printf("%s", ft_strcapitalize(str));
	return 0;
}