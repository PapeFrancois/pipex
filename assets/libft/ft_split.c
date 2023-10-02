/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:21:32 by hepompid          #+#    #+#             */
/*   Updated: 2022/11/24 16:23:36 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_of_lines(char const *s, char c)
{
	int	nbr;
	int	new_line;

	nbr = 0;
	new_line = 0;
	while (*s)
	{
		if (*s != c && new_line == 0)
		{
			new_line = 1;
			nbr++;
		}
		else if (*s == c && new_line == 1)
			new_line = 0;
		s++;
	}
	return (nbr);
}

static char	*ft_string_creator(char *str, char const *s, int start, int end)
{
	int	i;

	i = 0;
	str = malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (start < end)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = 0;
	return (str);
}

static	int	ft_malloc_error(char **table, int i)
{
	if (!table[i])
	{
		while (i >= 0)
		{
			free(table[i]);
			i--;
		}
		free(table);
		return (1);
	}
	return (0);
}

static char	**ft_fill_table(char **table, char const *s, char c)
{
	int	start;
	int	end;
	int	i;
	int	len;

	i = 0;
	start = -1;
	end = 0;
	len = ft_strlen(s);
	while (end <= len)
	{
		if (s[end] != c && s[end] != 0 && start == -1)
			start = end;
		if ((s[end] == c || end == len) && start != -1)
		{
			table[i] = ft_string_creator(table[i], s, start, end);
			if (ft_malloc_error(table, i) == 1)
				return (NULL);
			i++;
			start = -1;
		}
		end++;
	}
	table[i] = NULL;
	return (table);
}

char	**ft_split(char const *s, char c)
{
	char	**table;

	if (!s)
		return (NULL);
	table = malloc ((ft_number_of_lines(s, c) + 1) * sizeof(char *));
	if (!table)
		return (NULL);
	table = ft_fill_table(table, s, c);
	return (table);
}

// #include <stdio.h>

// int main()
// {
// 	char **str;
// 	int i = 0;
// 	char s[] = "      spli t";
// 	str = ft_split(s, ' ');
// 	if (!str)
// 		printf("lol");
// 	else
// 	{
// 		while (str[i])
// 		{
// 			printf("%s\n", str[i]);
// 			i++;
// 		}
// 		printf("%s\n", str[i]);
// 		free(str);
// 	}
// 	return (0);
// }
