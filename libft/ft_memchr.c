/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:12:35 by hepompid          #+#    #+#             */
/*   Updated: 2022/11/08 17:02:51 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "bergenge";
	char *ptr;
	ptr = memchr(str, 'g', 7);
	ptr = ft_memchr(str, 'g', 7);
	int i = 0;
	while (ptr[i])
	{
		printf("%c", ptr[i]);
		i++;
	}
	return (0);
}
*/