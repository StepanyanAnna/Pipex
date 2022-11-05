/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:42:27 by annstepa          #+#    #+#             */
/*   Updated: 2022/07/21 20:52:55 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path(char *argv, char **split2)
{
	int		i;
	char	*cmd1_0;
	char	*cmd1_1;
	char	**a;

	i = 0;
	while (split2[i])
	{
		cmd1_0 = ft_strjoin(split2[i], "/");
		a = ft_split(argv, ' ');
		cmd1_1 = ft_strjoin(cmd1_0, a[0]);
		if (access(cmd1_1, F_OK) == 0)
		{
			return (cmd1_1);
		}
		free(cmd1_0);
		free(cmd1_1);
			i++;
	}
	return (NULL);
}

char	*parsing(char *argv, char **envp)
{
	int		i;
	char	**split1;
	char	**split2;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			split1 = ft_split(envp[i], '=');
			split2 = ft_split(split1[1], ':');
			break ;
		}
		i++;
	}
	return (path(argv, split2));
}

// void	error_handling(char **arr)
// {
// 	int	i;
// 	i = 0;
// 	while (arr[i])
// 	{
// 		free(arr[i]);
// 		i++;
// 	}
// }

// void	child_1(int fd_write, int file1_fd, char **argv, char **envp)
// {
// 	int		to_in;
// 	int		to_out;
// 	char	**space;
// 	char	*path;
// 	to_in = dup2(file1_fd, stdin);
// 	close(file1_fd);
// 	to_out = dup2(fd_write, stdout);
// 	close(fd_write);
// 	if (to_in < 0 || to_out < 0)
// 	{
// 		perror("wrong");
// 		exit(EXIT_FAILURE);
// 	}
// 	path = parsing(argv, envp);
// 	space = ft_split(argv[2], ' ');
// 	if (execve(path, space, envp) == -1)
// 	{
// 		free(path);
// 		error_handling(space);
// 	}
// 	perror("execve failed");
// }

// void	chiled_2(int fd_read, int file2_fd, char **argv, char **envp)
// {
// 	int		form_cmd1_1;
// 	int		to_outfile;
// 	char	**space;
// 	char	*path;
// 	form_cmd1_1 = dup2(fd_read, stdin);
// 	close(fd_read);
// 	to_outfile = dup2(file2_fd, stdout);
// 	close(file2_fd);
// 	if (form_cmd1_1 < 0 || to_outfile < 0)
// 	{
// 		perror("something went wrong");
// 		exit(EXIT_FAILURE);
// 	}
// 	path = parsing(argv, envp);
// 	space = ft_split(argv[3], ' ');
// 	if (execve(path, space, envp) == -1)
// 	{
// 		free(path);
// 		error_handling(space);
// 	}
// 	perror("execve failed");
//}

// void	pipex(int argc, char **argv, char **envp)
// {
// 	int	pi;
// 	int	pid;									//reminder
// 	int	fds[2];
// 	pid = fork();
// 	pi = pipe(fds);
// 	if (pid < 0)
// 	{
// 		perror("Something went wrong");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (pi < 0)
// 	{
// 		perror("Fail");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (pid == 0)
// 	{
// 		chiled_1
// 	}
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	int	file1;
// 	int	file2;
// 	file1 = open(argv[1]);			//file1i fd
// 	file2 = open(argv[argc - 1]);	//modes O_CREAT
// 	parsing(argv, envp);
// }
