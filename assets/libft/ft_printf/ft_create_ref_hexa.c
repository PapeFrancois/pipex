/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_ref_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:24:46 by hepompid          #+#    #+#             */
/*   Updated: 2022/12/18 21:24:51 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexa_uppercase(char *str)
{
	int		i;
	char	c;

	str = malloc((16 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	c = '0';
	while (c <= 'F')
	{
		str[i] = c;
		if (c == '9')
			c = 'A';
		else
			c++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_hexa_lowercase(char *str)
{
	int		i;
	char	c;

	str = malloc((16 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	c = '0';
	while (c <= 'f')
	{
		str[i] = c;
		if (c == '9')
			c = 'a';
		else
			c++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_create_ref_hexa(char *str, int capitalize)
{
	if (capitalize == 1)
		str = ft_hexa_uppercase(str);
	else
		str = ft_hexa_lowercase(str);
	return (str);
}
