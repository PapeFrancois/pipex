/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:29:55 by hepompid          #+#    #+#             */
/*   Updated: 2022/11/24 16:56:11 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*table;

	if (size && SIZE_MAX / size < nmeb)
		return (NULL);
	table = malloc(nmeb * size);
	if (!table)
		return (NULL);
	ft_bzero(table, nmeb * size);
	return (table);
}

/*
#include <stdio.h>

int main()
{
	void *ptr;
	ptr = NULL;
	int nmeb = 2;
	int size = 3;
	ptr = ft_calloc(nmeb, size);
	int i = 0;
	while (i < (nmeb * size))
	{
		((char *)ptr)[i] = 'a';
		i++;
	}
	printf("%s\n", (char *)ptr);
	free(ptr);
	return (0);
}
*/
