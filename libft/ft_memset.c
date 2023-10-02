/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:17:36 by hepompid          #+#    #+#             */
/*   Updated: 2022/11/08 12:09:37 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char		*str;
	size_t		i;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>

int main()
{
	char s[3];
	ft_memset(s, 'b', 3);
	int i = 0;
	while (s[i])
	{
		printf("%c", s[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/