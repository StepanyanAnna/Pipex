/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:44:46 by annstepa          #+#    #+#             */
/*   Updated: 2022/07/21 21:28:49 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	in_file1;
	int	out_file2;

	in_file1 = open(argv[1], O_RDONLY);
	out_file2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (argc == 5)
	{
		pipex(in_file1, out_file2, argv, envp);
	}
}
