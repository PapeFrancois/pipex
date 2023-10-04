/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:46:55 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/04 18:34:05 by hepompid         ###   ########.fr       */
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

void	forker(int **fd, int *pid, int nofcommands, char **envp, char **argv)
{
	int	i;

	i = 0;
	while (i < nofcommands)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			error(fd, pid, nofcommands);
		if (pid[i] == 0)
		{
			
		}
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	**fd;
	int	*pid;
	int	nofcommands;

	if (argc < 5 || (argc < 6 && ft_strncmp(argv[1], "here_doc", 8) == 0))
		return (0);
	nofcommands = argc - 3;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		nofcommands = argc - 4;
	fd = fd_creat(nofcommands);
	pid = pid_creat(nofcommands, fd);
	fd = fd_init(argc, argv, fd, nofcommands);
	close_all_fd(fd, nofcommands);
	free_fd(fd, nofcommands);
	return (0);
}

// stocker fd, pid et nofcommands dans une structure