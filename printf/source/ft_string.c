/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:54:47 by asippy            #+#    #+#             */
/*   Updated: 2021/12/27 23:08:18 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_string(t_print *form)
{
	char	*str;
	int		len;
	int		res;

	str = va_arg(form->arg, char *);
	if (str == (void *)0)
		str = "(null)";
	len = ft_str_len(str);
	if (form->precision != -1 && form->precision < len)
		len = form->precision;
	res = len;
	if (form->width > res)
		res = form->width;
	ft_out_char_string(form, str, res, len);
	return (res);
}
