/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:05:27 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/06 13:09:31 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int	end_of_line(char *str, int read_count)
{
	int	i;

	if (read_count < BUFFER_SIZE && read_count > 0)
		return (1);
	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
	s'assure qu'on est pas a une fin de ligne, soit en trouvant \n,
	soit parce que c'est la fin du fichier.
*/

char	*str_fill(char *newline, char *buffer)
{
	if (!newline)
		newline = ft_strdup(buffer);
	else
		newline = ft_strjoin_free(newline, buffer);
	return (newline);
}

/*
	remplit la newline ou lui ajoute les caracteres contenus dans le buffer.
*/

char	*clean_end(char *newline)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(newline);
	while (newline[i] && newline[i] != '\n')
		i++;
	if (newline[i] == '\n')
		i++;
	while (i < len)
	{
		newline[i] = 0;
		i++;
	}
	return (newline);
}

/*
	retire dans newline tous les caracteres presents apres le \n
*/

int	check_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n' && buffer[++i] != 0)
	{
		while (buffer[i])
		{
			buffer[j] = buffer[i];
			i++;
			j++;
		}
		buffer[j] = '\0';
		return (1);
	}
	return (0);
}

/*
	check_buffer s'assure que le buffer a encore des caracteres apres 
	le saut de ligne, auquel cas il rapatrie tous les caracteres presents
	apres le saut de ligne au debut. suivi d'un strdup, il va permettre
	d'incorporer ces residus au debut de newline.
*/

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*newline;
	int			read_count;

	read_count = -1;
	newline = NULL;
	if (check_buffer(buffer[fd]) == 1)
	{
		newline = ft_strdup(buffer[fd]);
		if (!newline)
			return (NULL);
	}
	while (end_of_line(newline, read_count) == 0 && read_count != 0)
	{
		read_count = read(fd, buffer[fd], BUFFER_SIZE);
		if (read_count <= 0 && newline == NULL)
			return (NULL);
		buffer[fd][read_count] = 0;
		newline = str_fill(newline, buffer[fd]);
		if (!newline)
			return (NULL);
	}
	newline = clean_end(newline);
	return (newline);
}

/*
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int fd1 = open("get_next_line.h", O_RDONLY);
	char *str;

	str = get_next_line(fd1);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd1);
	}
	free(str);
	close(fd1);
	return 0;
}
*/
