/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:47:43 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/07 19:23:42 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_all_fd(int **fd, int nofcommands)
{
	int	i;

	i = 0;
	while (i < nofcommands)
	{
		if (fd[i][0] != -1)
			close(fd[i][0]);
		if (fd[i][1] != -1)
			close(fd[i][1]);
		i++;
	}
}

void	close_unused_fd(int **fd, int nofcommands, int benchmark)
{
	int	i;

	i = 0;
	while (i < nofcommands - 1)
	{
		if (i != benchmark)
		{
			close(fd[i][0]);
			close(fd[i + 1][1]);
		}
		i++;
	}
	if (benchmark != nofcommands - 1)
	{
		close(fd[nofcommands - 1][0]);
		close(fd[0][1]);
	}
}

int	**fd_init(int argc, char **argv, t_keyvar k)
{
	int	i;

	if (k.nofcommands == argc - 3)
	{
		k.fd[0][0] = open(argv[1], O_RDONLY);
		k.fd[0][1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else
	{
		k.fd[0][0] = here_doc(argv[2]);
		k.fd[0][1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	if (k.fd[0][0] == -1 || k.fd[0][1] == -1)
		perror("error");
	i = 0;
	while (++i < k.nofcommands)
		pipe(k.fd[i]);
	i = -1;
	while (++i < k.nofcommands)
	{
		if (k.fd[i][0] == -1 || k.fd[i][1] == -1)
			error(k);
	}
	return (k.fd);
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
