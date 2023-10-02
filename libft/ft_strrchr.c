/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:13:12 by hepompid          #+#    #+#             */
/*   Updated: 2022/11/08 14:22:49 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/*
#include <string.h>
#include <stdio.h>

int main()
{
	char str[] = "bergenge";
	printf("%s\n", strrchr(str, 'e'));
	printf("%s\n", ft_strrchr(str, 'e'));
	return (0);
}
*/