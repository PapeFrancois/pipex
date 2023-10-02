/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:16:46 by hepompid          #+#    #+#             */
/*   Updated: 2022/12/17 17:16:49 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_c_specifier(int character)
{
	unsigned char	c;

	c = (unsigned char)character;
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_i_d_specifier(int nbr)
{
	int	count;

	count = 0;
	ft_putnbr_fd(nbr, 1);
	if (nbr == -2147483648)
		count = 11;
	else if (nbr <= 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

int	ft_int_conv(int arg, char c)
{
	int	count;

	if (c == 'c')
		count = ft_c_specifier(arg);
	else
		count = ft_i_d_specifier(arg);
	return (count);
}
