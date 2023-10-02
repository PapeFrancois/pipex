/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:25:56 by hepompid          #+#    #+#             */
/*   Updated: 2022/12/17 15:25:59 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ordinary_chars(const char *format, int i)
{
	int	count;

	count = 0;
	while (format[i] != '\0' && format[i] != '%')
	{
		ft_putchar_fd(format[i], 1);
		i++;
		count++;
	}
	return (count);
}
