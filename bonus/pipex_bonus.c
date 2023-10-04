/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:46:55 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/04 16:04:12 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int	**fd;
	// int	*pid;
	int	nofcommands;

	(void)envp;

	if (argc < 5 || (argc < 6 && ft_strncmp(argv[1], "here_doc", 8) == 0))
		return (0);
	nofcommands = argc - 3;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		nofcommands = argc - 4;
	printf("nofcommands = %d\n", nofcommands);
	fd = fd_creat(nofcommands);
	fd = fd_init(argc, argv, fd, nofcommands);

	int i = 0;
	while (i < nofcommands)
	{
		printf("fd[%d][0] = %d, fd[%d][1] = %d\n", i, fd[i][0], i, fd[i][1]);
		i++;
	}
	
	close_all_fd(fd, nofcommands);
	free_fd(fd, nofcommands);
	return (0);
}
