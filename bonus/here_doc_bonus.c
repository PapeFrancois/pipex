/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:15:08 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/05 15:52:40 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*transform_into_readable(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
	{
		while (filename[i] < 97 || filename[i] > 122)
		{
			if (filename[i] < 97)
				filename[i] += 26;
			else if (filename[i] > 122)
				filename[i] -= 26;
		}
		i++;
	}
	return (filename);
}

char	*get_filename(char *filename)
{
	int		fd;
	char	*tmp;

	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		return (NULL);
	tmp = get_next_line(fd);
	close(fd);
	if (!tmp)
		return (NULL);
	filename = ft_substr(tmp, 0, 10);
	free(tmp);
	if (!filename)
		return (NULL);
	filename = transform_into_readable(filename);
	return (filename);
}

int	fill_file(char *filename, char *limiter)
{
	int		len;
	int		fd;
	char	*str;

	str = NULL;
	len = ft_strlen(limiter);
	fd = open(filename, O_WRONLY | O_CREAT, S_IRWXU);
	if (fd == -1)
		return (1);
	str = get_next_line(0);
	if (!str)
		return (1);
	while (ft_strncmp(limiter, str, len) != 0 || str[len] != '\n')
	{
		ft_putstr_fd(str, fd);
		free(str);
		str = get_next_line(0);
		if (!str)
			return (1);
	}
	free(str);
	fd = close(fd);
	if (fd == -1)
		return (1);
	return (0);
}

int	here_doc(char *limiter)
{
	char	*filename;
	int		fd;

	filename = NULL;
	filename = get_filename(filename);
	if (!filename)
		return (-1);
	if (fill_file(filename, limiter) == 1)
		return (-1);
	fd = open(filename, O_RDONLY);
	unlink(filename);
	free(filename);
	return (fd);
}
