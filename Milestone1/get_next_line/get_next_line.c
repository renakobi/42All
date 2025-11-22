/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 20:37:57 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/06/23 13:15:26 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*str;

	buffer = (char *)malloc(((BUFFER_SIZE) + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free (str);
		free (buffer);
		str = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = fill_line_buffer(fd, str, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	str = set_line(line);
	return (line);
}
//mallocs buffer then checks for possible errors
//( if fd is negative it is an error message) same for read. 
//if buff size is null or negative it will craash the program
//it frees the strings so it resets for nextline.
//if there are no errors but a string is empty it returns null
//after all checks it sends string and buffer to fill

char	*fill_line_buffer(int fd, char *string, char *buffer)
{
	ssize_t	reader;
	char	*temp;

	reader = 1;
	while (reader > 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(string);
			return (NULL);
		}
		else if (reader == 0)
			break ;
		buffer[reader] = 0;
		if (!string)
			string = ft_strdup("");
		temp = string;
		string = ft_strjoin(temp, buffer);
		free (temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (string);
}

char	*set_line(char *line_buff)
{
	char	*str;
	int		i;

	i = 0;
	if (!line_buff)
		return (NULL);
	while (line_buff[i] != '\0' && line_buff[i] != '\n')
		i++;
	if (line_buff[i] == 0 || line_buff[i + 1] == 0)
		return (NULL);
	str = ft_substr(line_buff, i + 1, ft_strlen(line_buff) - i);
	if (!str || *str == 0)
	{
		free(str);
		str = NULL;
	}
	line_buff[i + 1] = '\0';
	return (str);
}
/*so getnextline checks file descriptor and handles main mallocs.
 it then calls the fill line function until it reaches a \n or \0 
 after that we free the buffer to avoid memory leaks
  then we set the line in the set line function which returns the read line
  then it is stored in a static variable so when the getnextline function 
  is called again it knows where the new line is*/
/*
  int main(void)
{
	int     fd;
	char    *line;

	fd = open("ok.txt", O_RDONLY); // Replace with your own file path
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/