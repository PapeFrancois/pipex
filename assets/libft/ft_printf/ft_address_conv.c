/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:10:26 by hepompid          #+#    #+#             */
/*   Updated: 2022/12/18 22:10:29 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(long unsigned int nbr, char *str)
{
	int	count;

	count = 1;
	if (nbr >= 16)
		count += ft_print_hexa(nbr / 16, str);
	ft_putchar_fd(str[nbr % 16], 1);
	return (count);
}

int	ft_address_conv(void *address)
{
	long unsigned int	nbr;
	int					count;
	char				*str;

	str = NULL;
	nbr = (long unsigned int)address;
	if (nbr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = 2;
	str = ft_create_ref_hexa(str, 0);
	if (!str)
		return (0);
	count += ft_print_hexa(nbr, str);
	free(str);
	return (count);
}
