/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:07:37 by annstepa          #+#    #+#             */
/*   Updated: 2022/07/21 20:40:54 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int f1, int f2, char **argv, char **envp)
{
	int		fds[2];
	pid_t	childpid1;
	pid_t	pid2;
	int		status;

	error_pipe(pipe(fds));
	childpid1 = fork();
	error_pid(childpid1);
	if (childpid1 == 0)
	{
		close(fds[0]);
		child_1(fds[1], f1, argv, envp);
	}
	pid2 = fork();
	error_pid(pid2);
	if (pid2 == 0)
	{
		close(fds[1]);
		child_2(fds[0], f2, argv, envp);
	}
	close(fds[0]);
	close(fds[1]);
	waitpid(childpid1, &status, 0);
	waitpid(pid2, &status, 0);
}
