/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:34:10 by annstepa          #+#    #+#             */
/*   Updated: 2022/07/21 20:41:05 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handling(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	error_pid(pid_t pid)
{
	if (pid < 0)
	{
		perror("Wrong");
		exit(EXIT_FAILURE);
	}
}

void	error_pipe(int pipe_return)
{
	if (pipe_return < 0)
	{
		perror("Pipe error");
		exit(EXIT_FAILURE);
	}
}
