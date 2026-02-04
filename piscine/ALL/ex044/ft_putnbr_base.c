/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:16:12 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/04/22 18:05:14 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	validate_base(char *base)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = 0;
	while (base[size])
		size ++;
	if (size <= 1)
		return (0);
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (base[i] == base[j] || base[i] < 0)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	c;
	int		i;
	int		j;
	int		temp;

	i = 0;
	c = '-';
	if (validate_base(base))
	{
		while (base[i])
			i ++;
		if (nbr < 0)
			write(1, &c, 1);
		while (nbr != 0)
		{
			j = 0;
			temp = nbr % i;
			nbr /= i;
			write (1, &temp, 1);
			j ++;
		}
	}
}
