/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:52:17 by hepompid          #+#    #+#             */
/*   Updated: 2022/11/09 12:25:38 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	if (!len)
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (little[j] == 0)
			{
				return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}

/*
#include <string.h>
#include <stdio.h>

int main()
{
	char big[] = "bergenge dit toby";
	char little[] = "toby";
	printf("%s\n", ft_strnstr(big, little, 0));
	printf("%s\n", strnstr(big, little, 0));
	return (0);
}
*/