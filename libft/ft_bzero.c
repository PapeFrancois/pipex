/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:32:04 by hepompid          #+#    #+#             */
/*   Updated: 2022/11/08 12:21:06 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n > 0)
	{
		*str = 0;
		n--;
		str++;
	}
}

/*
#include <stdio.h>

int main()
{
	char s[] = "aaa";
	int i = 0;
	int n = 3;
	ft_bzero(s, 1);
	while (i < n)
	{
		printf("%c", s[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/