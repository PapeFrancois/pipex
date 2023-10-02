/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:28:24 by hepompid          #+#    #+#             */
/*   Updated: 2022/11/24 16:29:12 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size_substr(char const *s, unsigned int start, size_t len)
{
	if (start > ft_strlen(s))
		return (0);
	if (len < (ft_strlen(s) - start))
		return (len);
	return (ft_strlen(s) - start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	size = ft_size_substr(s, start, len);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}

/*
#include <stdio.h>

int main()
{
	char s[] = "0123456789";
	printf("%zu\n", ft_size_substr(s, 12, 7));
	return (0);
}
*/