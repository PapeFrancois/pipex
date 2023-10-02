/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:42:38 by hepompid          #+#    #+#             */
/*   Updated: 2022/11/24 16:43:10 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;
	size_t		i;

	i = 0;
	if (!n || dst == src)
		return (dst);
	s1 = (char *)dst;
	s2 = (const char *)src;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char buff1[22];
	char src[] = "test basic du memcpy!";
	// memcpy(buff1, src, 22);
	ft_memcpy(buff1, src, 22);
	int i = 0;
	while (buff1[i])
	{
		printf("%c", buff1[i]);
		i++;
	}
	return (0);
}
*/
