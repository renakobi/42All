/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:52:48 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/04/30 22:32:18 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	a;

	a = nb;
	if (power == 0 || nb == 1)
		return (1);
	if (nb == 0 || power < 0)
		return (0);
	while (power > 1)
	{
		a *= nb;
		power --;
	}
	return (a);
}
