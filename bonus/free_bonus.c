/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:39:54 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/05 14:21:29 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_table(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

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

void	error(t_keyvar key)
{
	close_all_fd(key.fd, key.nofcommands);
	free_fd(key.fd, key.nofcommands);
	free(key.pid);
	exit(0);
}
