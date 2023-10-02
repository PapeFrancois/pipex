/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:59:29 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/02 18:45:50 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child2(char **argv, char **envp, int *fd)
{
	int 	fd_output;
	char	**split_arg;
	char	*final_path;
	
	printf("entree child2\n");
	split_arg = NULL;
	close(fd[1]);
	fd_output = open((argv[4]), O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (fd_output == -1)
		exit (0);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_output, STDOUT_FILENO);
	close(fd[0]);
	close(fd_output);
	final_path = path_finder(argv[3], envp);
	split_arg = ft_split(argv[3], ' ');
		printf("final path = %s\n", final_path);
	int i = 0;
	while (split_arg[i])
	{
		printf("%s\n", split_arg[i]);
		i++;
	}
	execve(final_path, split_arg, NULL);
	free(final_path);
	free_table(split_arg);
	return(0);
}

int	child(char **argv, char **envp, int *fd)
{
	int 	fd_input;
	char	**split_arg;
	char	*final_path;
	
	printf("entree child1\n");
	split_arg = NULL;
	close(fd[0]);
	fd_input = open((argv[1]), O_RDONLY);
	if (fd_input == -1)
		exit (0);
	dup2(fd_input, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd_input);
	close(fd[1]);
	final_path = path_finder(argv[2], envp);
	split_arg = ft_split(argv[2], ' ');
	printf("final path = %s\n", final_path);
	int i = 0;
	while (split_arg[i])
	{
		printf("%s\n", split_arg[i]);
		i++;
	}
	execve(final_path, split_arg, NULL);
	free(final_path);
	free_table(split_arg);
	return(0);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)argc;
	int	fd[2];
	int pid[2];
	
	if (argc < 5)
		return (0);
	if (pipe(fd) == -1)
		return (0);
	printf("fd[0] = %d, fd[1] = %d\n", fd[0], fd[1]);
	pid[0] = fork();
	if (pid[0] == -1)
		return (0);
	else if (pid[0] == 0)
		child(argv, envp, fd);
	pid[1] = fork();
	if (pid[1] == -1)
		return (0);
	else if (pid[1] == 0)
		child2(argv, envp, fd);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (0);
}
