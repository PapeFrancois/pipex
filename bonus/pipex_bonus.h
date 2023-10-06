/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:47:09 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/06 13:09:49 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../assets/libft/libft.h"

typedef struct s_keyvar
{
	int	nofcommands;
	int	**fd;
	int	*pid;
}	t_keyvar;

int		**fd_creat(int nofcommands);
int		**fd_init(int argc, char **argv, t_keyvar key);
void	free_fd(int **fd, int nofcommands);
void	malloc_error(int **fd, int i);
void	close_all_fd(int **fd, int nofcommands);
void	error(t_keyvar key);
void	close_unused_fd(int **fd, int nofcommands, int benchmark);
void	free_table(char **table);
char	*path_finder(char *arg, char **envp);
int		here_doc(char *limiter);
char	*ft_strjoin_free(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif
