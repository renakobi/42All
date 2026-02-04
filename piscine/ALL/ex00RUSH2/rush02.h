/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:11:14 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/04/27 20:56:31 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict
{
	unsigned long long	number;
	char				*word;
}	t_dict;

int					ft_strlen(char *str);
char				*ft_strdup(char *src);
void				ft_putstr(char *str);
void				ft_puterror(char *str);
void				free_dict(t_dict *dict, int size);
unsigned long long	ft_atoull(char *str);
int					is_valid_number(char *str);

int					parse_dict(char *filename, t_dict **dict, int *size);
char				*get_word(t_dict *dict, int size, unsigned long long nb);

void				print_number(t_dict *dict, int size, unsigned long long nb);
void				print_single_word(t_dict *dict, int size,
						unsigned long long nb);
#endif
