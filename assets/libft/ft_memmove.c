/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:37:29 by hepompid          #+#    #+#             */
/*   Updated: 2022/11/24 16:58:32 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;
	size_t		i;

	if (!dst && !src)
		return (((void *)0));
	s1 = (char *)dst;
	s2 = (const char *)src;
	i = 0;
	if (s1 > s2)
	{
		while (n-- > 0)
		{
			s1[n] = s2[n];
		}
	}
	else
	{
		while (i < n)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	// char *a = ((void *)0);
	memmove(((void *)0), ((void *)0), 5);
	ft_memmove(((void *)0), ((void *)0), 5);
	// int i = 0;
	// while (a[i])
	// {
	// 	printf("%c", a[i]);
	// 	i++;
	// }
	return (0);
}
*/
