/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:14:17 by hepompid          #+#    #+#             */
/*   Updated: 2022/12/17 15:14:22 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;

	i = 0;
	lensrc = ft_strlen(src);
	if (!size)
		return (lensrc);
	lendst = ft_strlen(dst);
	while (src[i] && lendst + i < size - 1)
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = 0;
	if (lendst > size)
		return (lensrc + size);
	return (lensrc + lendst);
}

/*
#include <stdio.h>
#include <bsd/string.h>
#include <unistd.h>

int main()
{
	char dest[] = "rrrrrrrrrrrrrrr";
	char src[] = "lorem ipsum dolor sit amet";
	// printf("%zu\n", strlcat(dest, src, 15));
	printf("%zu\n", ft_strlcat(dest, src, 15));
	write(1, dest, 15);
	return (0);
}

//penser a ajouter -lbsd a la compilation tt a la fin 
//pour comparer avec l'originale
*/
