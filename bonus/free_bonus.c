/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:39:54 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/04 18:31:28 by hepompid         ###   ########.fr       */
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
	while (i < nofcommands)
	{
		free(fd[i]);
		i++;
	}
	free(fd);
}

void	error(int **fd, int *pid, int nofcommands)
{
	free_fd(fd, nofcommands);
	free(pid);
	close_all_fd(fd, nofcommands);
	exit(0);
}