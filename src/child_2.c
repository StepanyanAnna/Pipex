/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:47:38 by annstepa          #+#    #+#             */
/*   Updated: 2022/07/20 21:22:23 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_2(int fd_read, int file2_fd, char **argv, char **envp)
{
	char	*path2;
	char	**space2;
	int		to_outfile;
	int		from_cmd1_1;

	from_cmd1_1 = dup2(fd_read, STDIN_FILENO);
	close(fd_read);
	to_outfile = dup2(file2_fd, STDOUT_FILENO);
	close(file2_fd);
	if (to_outfile < 0 || from_cmd1_1 < 0)
	{
		perror("Something went wrong");
		exit(EXIT_FAILURE);
	}
	path2 = parsing(argv[3], envp);
	space2 = ft_split(argv[3], ' ');
	execve(path2, space2, envp);
	free(path2);
	error_handling(space2);
	perror("hi");
}
