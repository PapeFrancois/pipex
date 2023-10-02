/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <hepompid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:44:28 by hepompid          #+#    #+#             */
/*   Updated: 2023/10/02 18:45:56 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
	{
		free ((char *)s1);
		return (NULL);
	}
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free((char *)s1);
	return (str);
}

char	**path_init(char **envp)
{
	char	**list_of_paths;
	char	*temp;
	int		i;

	list_of_paths = NULL;
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		list_of_paths = ft_split(envp[i], ':');
	if (!list_of_paths)
		return (NULL);
	temp = ft_substr(list_of_paths[0], 5, ft_strlen(list_of_paths[0]));
	if (!temp)
	{
		free_table(list_of_paths);
		exit(0);
	}
	free(list_of_paths[0]);
	list_of_paths[0] = temp;
	i = 0;
	while (list_of_paths[i])
	{
		list_of_paths[i] = ft_strjoin_free(list_of_paths[i], "/");
		i++;
	}
	return (list_of_paths);
}

char	*check_access(char **list_of_paths, char *cmd)
{
	char	*final_path;
	int		i;

	i = 0;
	while (list_of_paths[i])
	{
		final_path = ft_strjoin(list_of_paths[i], cmd);
		if (access(final_path, F_OK) == 0)
			return (final_path);
		free(final_path);
		i++;
	}
	return (NULL);
}

char	*path_finder(char *arg, char **envp)
{
	char	*final_path;
	char	**split_arg;
	char	**list_of_paths;

	final_path = NULL;
	split_arg = NULL;
	list_of_paths = path_init(envp);
	split_arg = ft_split(arg, ' ');
	if (!split_arg)
	{
		free_table(list_of_paths);
		exit(0);
	}
	if (access(split_arg[0], F_OK) == 0)
		final_path = split_arg[0];
	else
		final_path = check_access(list_of_paths, split_arg[0]);
	free_table(list_of_paths);
	free_table(split_arg);
	return (final_path);
}