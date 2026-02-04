/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:11:38 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/04/27 21:02:26 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

unsigned long long	parse_number(char *str);
void				skip_spaces(char **str);

static int	count_lines(char *buf)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

static int	fill_entry(t_dict *dict, char **ptr)
{
	int	j;

	j = 0;
	skip_spaces(ptr);
	dict->number = parse_number(*ptr);
	while (**ptr && **ptr != ':')
		(*ptr)++;
	if (**ptr == ':')
		(*ptr)++;
	skip_spaces(ptr);
	while ((*ptr)[j] && (*ptr)[j] != '\n')
		j++;
	(*ptr)[j] = '\0';
	dict->word = ft_strdup(*ptr);
	*ptr += j + 1;
	return (1);
}

int	parse_dict(char *filename, t_dict **dict, int *size)
{
	int		fd;
	int		r;
	int		i;
	char	buf[10000];
	char	*ptr;

	filename = "numbers.dict";
	fd = open(filename, O_RDONLY);
	r = read(fd, buf, 9999);
	if (fd < 0 || r < 0)
		return (0);
	buf[r] = '\0';
	close(fd);
	*size = count_lines(buf);
	*dict = (t_dict *)malloc(sizeof(t_dict) * (*size));
	if (!(*dict))
		return (0);
	ptr = buf;
	i = 0;
	while (*ptr)
		fill_entry(&(*dict)[i++], &ptr);
	return (1);
}

char	*get_word(t_dict *dict, int size, unsigned long long nb)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (dict[i].number == nb)
			return (dict[i].word);
		i++;
	}
	return (NULL);
}
