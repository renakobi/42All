/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:48:46 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/09/23 19:04:08 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_pipe
{
	int		infile;
	int		cmd1;
	int		cmd2;
	int		outfile;
	char	**env;
}	t_pipe;
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	**ft_split(const char *s, char c);
void	cmd1(int *fd, char **argv, char **paths, t_pipe pipes);
void	cmd2(int *fd, char **argv, char **paths, t_pipe pipes);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	*ft_free(char **strs, int count);
char	**get_path(char **envs);
void	free_paths(char **strs);
void	cleanup_and_exit(char *path, char **temp, char **paths, int code);
void	checker(char *path, char **paths, t_pipe pipes, char **temp);
#endif