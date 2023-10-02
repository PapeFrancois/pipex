/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:12:42 by hepompid          #+#    #+#             */
/*   Updated: 2022/11/24 16:16:52 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (2);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

static char	*ft_fill(int n, int len, char *ptr)
{
	int	sign;

	len--;
	ptr[len] = '\0';
	if (n == 0)
		ptr[0] = '0';
	sign = 0;
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	len--;
	while (n > 0)
	{
		ptr[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	if (sign == 1)
		ptr[0] = '-';
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ptr;
	int		stock;

	stock = n;
	if (n == -2147483648)
		stock++;
	len = ft_length(stock);
	ptr = malloc(len * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr = ft_fill(stock, len, ptr);
	if (stock == n + 1)
		ptr[len - 2] = '8';
	return (ptr);
}

/*
#include <stdio.h>

int main()
{
	char *ptr;

	ptr = ft_itoa(-2147483648);
	printf("%s\n", ptr);
	free(ptr);
	return (0);
}
*/
