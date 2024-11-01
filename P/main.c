/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:36:56 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/10/31 14:28:53 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/libft.h"
#include <fcntl.h>
#include <sys/wait.h>
#include "pipex.h"

void	parent(int *pipefd, char *argv, char **envp, int fd)
{
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	if (fd != -1)
		close(fd);
	close(pipefd[0]);
	ex(argv, envp);
	if (fd != -1)
	{
		ft_putstr_fd("command error : ", 2);
		ft_putstr_fd(argv, 2);
		write(2, "\n\n", 1);
	}
	exit(EXIT_FAILURE);
}

void	enfant(int *pipefd, char *argv, char **envp, int fd)
{
	close(pipefd[0]);
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	if (fd != -1)
	{
		close(fd);
		ex(argv, envp);
	}
	if (fd != -1)
	{
		ft_putstr_fd("command error : ", 2);
		ft_putstr_fd(argv, 2);
		write(2, "\n\n", 1);
	}
	exit(EXIT_FAILURE);
}

int	pipex(int f1, int f2, char **env, char **argv)
{
	int	pipefd[2];
	int	id[2];
	int	status;

	status = 0;
	if (pipe(pipefd) == -1)
		return (perror("pipe"), -1);
	id[0] = lefork();
	if (id[0] == 0)
	{
		if (f2 != -1)
			close(f2);
		enfant(pipefd, argv[2], env, f1);
	}
	id[1] = lefork();
	if (id[1] == 0)
	{
		if (f2 != -1)
			close(f1);
		parent(pipefd, argv[3], env, f2);
	}
	status = c_and_w(pipefd, id, status);
	return (WEXITSTATUS(status));
}

int	my_open(char **ar, int *fd)
{
	fd[0] = -1;
	fd[1] = -1;
	if (access(ar[1], F_OK) == -1)
		printf("zsh: no such file or directory: %s \n\n", ar[1]);
	if (access(ar[1], R_OK) == -1)
		printf("zsh: permission denied: %s \n\n", ar[1]);
	fd[0] = open(ar[1], O_RDONLY, 644);
	if (fd[0] < 0)
		printf("can't open %s \n\n", ar[1]);
	fd[1] = open(ar[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (access(ar[4], R_OK | W_OK) == -1)
	{
		if (fd[0] != -1)
			close(fd[0]);
		printf("zsh: permission denied: %s \n\n", ar[4]);
		exit(1);
	}
	if (fd[1] < 0)
	{
		if (fd[0] != -1)
			close(fd[0]);
		return (printf("can't open: %s \n\n", ar[4]), -1);
	}
	return (0);
}

int	main(int argc, char *argv[], char **envp)
{
	int	s;
	int	fd[2];
	int	i;

	if (argc != 5)
		return (printf("incorrect numbers of arguments\n\n"), -1);
	i = 0;
	my_open(argv, fd);
	s = pipex(fd[0], fd[1], envp, argv);
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
	return (s);
}
