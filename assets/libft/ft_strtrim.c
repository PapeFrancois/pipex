/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:24:23 by hepompid          #+#    #+#             */
/*   Updated: 2022/11/24 16:27:22 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkup(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (ft_checkup(s1[i], set) == 1)
		i++;
	return (i);
}

static int	ft_end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (ft_checkup(s1[i], set) == 1 && i > 0)
		i--;
	return (i);
}

static char	*ft_fill(char *str, char const *s1, int start, int end)
{
	int	i;

	i = 0;
	while (start <= end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	str = malloc((end - start + 2) * sizeof(char));
	if (!str)
		return (NULL);
	str = ft_fill(str, s1, start, end);
	return (str);
}

/*
#include <stdio.h>

int main()
{
	char const s1[] = "//////";
	char const set[] = "/";
	char *str = ft_strtrim(s1, set);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/