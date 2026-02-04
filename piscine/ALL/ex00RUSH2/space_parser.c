/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:22:48 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/04/27 20:57:41 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	parse_number(char *str)
{
	unsigned long long	nb;

	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb);
}

void	skip_spaces(char **str)
{
	while (**str == ' ' || **str == '\t')
		(*str)++;
}
