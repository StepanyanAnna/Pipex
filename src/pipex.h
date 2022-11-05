/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annstepa <annstepa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:07:17 by annstepa          #+#    #+#             */
/*   Updated: 2022/07/21 20:41:32 by annstepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include <fcntl.h>
# include <time.h>

int		ft_strlen(const char *str);
int		main(int argc, char **argv, char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*strdup(const char *s1);
char	**ft_split(char const *s, char c);
char	*parsing(char *argv, char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
void	error_handling(char **arr);
void	pipex(int f1, int f2, char **argv, char **envp);
void	child_1(int fd_write, int file1_fd, char **argv, char **envp);
void	child_2(int fd_read, int file2_fd, char **argv, char **envp);
void	error_handling(char **arr);
void	error_pid(pid_t pid);
void	error_pipe(int pipe_return);

#endif
