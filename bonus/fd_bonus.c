/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:47:43 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/04 15:29:18 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	malloc_error(int **fd, int i)
{
	while (i >= 0)
	{
		free(fd[i]);
		i--;
	}
	free(fd);
	exit(0);
}

void	free_fd(int **fd, int nofcommands)
{
	int	i;

	i = 0;
	while (i > nofcommands)
	{
		free(fd[i]);
		i++;
	}
	free(fd);
}

int	**fd_init(int argc, char **argv, int **fd, int nofcommands)
{
	int	i;

	if (nofcommands == argc - 3)
	{
		fd[0][0] = open(argv[1], O_RDONLY);
		fd[0][1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else
	{
		// fd[0][0] = heredoc();
		fd[0][1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	i = 0;
	while (++i < nofcommands)
		pipe(fd[i]);
	i = -1;
	while (++i < nofcommands)
	{
		if (fd[i][0] == -1 || fd[i][1] == -1)
		{
			free_fd(fd, nofcommands);
			exit (0);
		}
	}
	return (fd);
}

int	**fd_creat(int nofcommands)
{
	int	**fd;
	int	i;

	fd = malloc(nofcommands * sizeof(int *));
	if (!fd)
		exit (0);
	i = 0;
	while (i < nofcommands)
	{
		fd[i] = malloc(2 * sizeof(int));
		if (!fd[i])
		{
			malloc_error(fd, i - 1);
			exit(0);
		}
		i++;
	}
	return (fd);
}
