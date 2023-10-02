/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heloise <heloise@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:23:51 by hepompid          #+#    #+#             */
/*   Updated: 2023/03/22 15:43:09 by heloise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft.h"

char	*ft_create_ref_hexa(char *str, int capitalize);
int		ft_address_conv(void *address);
int		ft_get_to_conversion(const char *format, int i);
int		ft_int_conv(int var, char c);
int		ft_is_percent(char c);
int		ft_printf(const char *format, ...);
int		ft_print_ordinary_chars(const char *format, int i);
int		ft_string_conv(char *str);
int		ft_u_int_conv(unsigned int var, char c);

#endif
