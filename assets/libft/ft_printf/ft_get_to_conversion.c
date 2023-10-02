/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_navigate_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepompid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:39:00 by hepompid          #+#    #+#             */
/*   Updated: 2022/12/17 15:39:03 by hepompid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_to_conversion(const char *format, int i)
{
	while (format[i] && format[i] != '%')
		i++;
	if (format[i] == '%')
		i++;
	return (i);
}
