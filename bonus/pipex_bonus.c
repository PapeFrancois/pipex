/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:46:55 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/05 12:01:46 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	*pid_creat(int nofcommands, int **fd)
{
	int	*pid;

	pid = malloc(nofcommands * sizeof(int));
	if (!pid)
	{
		free_fd(fd, nofcommands);
		exit(0);
	}
	return (pid);
}

void	duptwo(t_keyvar key, int i)
{
	if (i == key.nofcommands - 1)
	{
		dup2(key.fd[key.nofcommands - 1][0], STDIN_FILENO);
		dup2(key.fd[0][1], STDOUT_FILENO);
		close(key.fd[key.nofcommands - 1][0]);
		close(key.fd[0][1]);
	}
	else
	{
		dup2(key.fd[i][0], STDIN_FILENO);
		dup2(key.fd[i + 1][1], STDOUT_FILENO);
		close(key.fd[i][0]);
		close(key.fd[i + 1][1]);
	}
}

void	child(char *arg, char **envp, t_keyvar key, int i)
{
	char	**split_arg;
	char	*final_path;

	split_arg = NULL;
	close_unused_fd(key.fd, key.nofcommands, i);
	duptwo(key, i);
	final_path = path_finder(arg, envp);
	if (!final_path)
		return ;
	split_arg = ft_split(arg, ' ');
	if (execve(final_path, split_arg, envp) == -1)
	{
		free_table(split_arg);
		free(final_path);
		error(key);
	}
}

void	forker(t_keyvar key, char **argv, char **envp)
{
	int	i;
	int	first_command;

	first_command = 2;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		first_command = 3;
	i = 0;
	while (i < key.nofcommands)
	{
		key.pid[i] = fork();
		if (key.pid[i] == -1)
			error(key);
		if (key.pid[i] == 0)
			child(argv[first_command + i], envp, key, i);
		i++;
	}
}

void	waiter(t_keyvar key)
{
	int	i;

	i = 0;
	while (i < key.nofcommands)
	{
		waitpid(key.pid[i], NULL, 0);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_keyvar	key;

	if (argc < 5 || (argc < 6 && ft_strncmp(argv[1], "here_doc", 8) == 0))
		return (0);
	key.nofcommands = argc - 3;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		key.nofcommands = argc - 4;
	key.fd = fd_creat(key.nofcommands);
	key.pid = pid_creat(key.nofcommands, key.fd);
	key.fd = fd_init(argc, argv, key.fd, key.nofcommands);
	forker(key, argv, envp);
	close_all_fd(key.fd, key.nofcommands);
	free_fd(key.fd, key.nofcommands);
	free(key.pid);
	return (0);
}

// stocker fd, pid et nofcommands dans une structure