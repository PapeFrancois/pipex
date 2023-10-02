/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:46:37 by hepompid          #+#    #+#             */
/*   Updated: 2022/12/18 10:46:40 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_putnbr_fd(unsigned int nbr, int fd)
{
	if (nbr > 9)
		ft_unsigned_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((nbr % 10) + 48, fd);
}

int	ft_u_specifier(unsigned int nbr)
{
	int	count;

	ft_unsigned_putnbr_fd(nbr, 1);
	if (nbr == 0)
		return (1);
	count = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

int	ft_x_specifier(unsigned int nbr, char *str)
{
	int	count;

	count = 1;
	if (nbr >= 16)
		count += ft_x_specifier(nbr / 16, str);
	ft_putchar_fd(str[nbr % 16], 1);
	return (count);
}

int	ft_u_int_conv(unsigned int arg, char c)
{
	int		count;
	char	*str;

	str = NULL;
	count = 0;
	if (c == 'u')
		count = ft_u_specifier(arg);
	else
	{
		if (c == 'X')
			str = ft_create_ref_hexa(str, 1);
		else
			str = ft_create_ref_hexa(str, 0);
		if (!str)
			return (0);
		count = ft_x_specifier(arg, str);
	}
	free(str);
	return (count);
}
