/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:47:27 by annstepa          #+#    #+#             */
/*   Updated: 2022/07/20 22:03:30 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_1(int fd_write, int file1_fd, char **argv, char **envp)
{
	int		to_in;
	int		to_out;
	char	*path;
	char	**space;

	to_in = dup2(file1_fd, STDIN_FILENO);
	close(file1_fd);
	to_out = dup2(fd_write, STDOUT_FILENO);
	close(fd_write);
	if (to_in < 0 || to_out < 0)
	{
		perror("Error found");
		exit(EXIT_FAILURE);
	}
	path = parsing(argv[2], envp);
	space = ft_split(argv[2], ' ');
	execve(path, space, envp);
	free(path);
	error_handling(space);
	perror("llll");
}
