/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:39:54 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/04 16:05:25 by hepompid         ###   ########.fr       */
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
