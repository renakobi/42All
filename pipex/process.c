/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:48:39 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/09/23 19:05:12 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//infile cmd1 | cmd2 outfile
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "pipex.h"

static char	*ft_getenv(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			return (env[i] + 5);
		}
		i++;
	}
	return (NULL);
}

static char	*get_cmd_path(char *cmd, char **paths)
{
	int		i;
	char	*tmp;
	char	*full_path;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return (NULL);
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!full_path)
			return (NULL);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	**get_path(char **envs)
{
	char	*path;
	char	**temp;

	path = ft_getenv(envs);
	if (!path)
		return (NULL);
	temp = ft_split(path, ':');
	return (temp);
}

void	cmd1(int *fd, char **argv, char **paths, t_pipe pipes)
{
	char	**temp;
	char	*path;
	int		count;

	pipes.infile = open(argv[1], O_RDONLY);
	if (pipes.infile == -1)
	{
		perror(argv[1]);
		free_paths(paths);
		exit(1);
	}
	dup2(pipes.infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	temp = ft_split(argv[2], ' ');
	count = 0;
	while (temp[count])
		count++;
	path = get_cmd_path(temp[0], paths);
	checker(path, paths, pipes, temp);
	free_paths(temp);
}

void	cmd2(int *fd, char **argv, char **paths, t_pipe pipes)
{
	char	**temp;
	char	*path;
	int		count;

	pipes.outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipes.outfile == -1)
	{
		perror(argv[4]);
		free_paths(paths);
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(pipes.outfile, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	temp = ft_split(argv[3], ' ');
	count = 0;
	while (temp[count])
		count++;
	path = get_cmd_path(temp[0], paths);
	checker(path, paths, pipes, temp);
	free_paths(temp);
}
