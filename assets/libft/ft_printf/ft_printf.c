/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:29:55 by hepompid          #+#    #+#             */
/*   Updated: 2022/12/17 15:30:05 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		count += ft_print_ordinary_chars(format, i);
		i = ft_get_to_conversion(format, i);
		if (format[i] == 'd' || format[i] == 'i' || format[i] == 'c')
			count += ft_int_conv(va_arg(args, int), format[i]);
		if (format[i] == 'u' || format[i] == 'x' || format[i] == 'X')
			count += ft_u_int_conv(va_arg(args, unsigned int), format[i]);
		if (format[i] == 's')
			count += ft_string_conv(va_arg(args, char *));
		if (format[i] == 'p')
			count += ft_address_conv(va_arg(args, void *));
		count += ft_is_percent(format[i]);
		if (format[i] != '\0')
			i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>

// int main()
// {
// 	ft_printf("%d\n", ft_printf("test : %x\n", 498));
// 	return (0);
// }
