/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:47:43 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/04 15:53:28 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_all_fd(int **fd, int nofprocess)
{
	int	i;

	i = 0;
	while (i < nofprocess)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

void	close_unused_fd(int **fd, int nofprocess, int benchmark)
{
	int	i;

	i = 0;
	while (i < nofprocess - 1)
	{
		if (i != benchmark)
		{
			close(fd[i][0]);
			close(fd[i + 1][1]);
		}
		i++;
	}
	if (benchmark != nofprocess - 1)
	{
		close(fd[nofprocess - 1][0]);
		close(fd[0][1]);
	}
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
