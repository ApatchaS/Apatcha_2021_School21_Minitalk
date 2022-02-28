/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:16:11 by asippy            #+#    #+#             */
/*   Updated: 2022/03/01 00:16:11 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/ft_printf_bonus.h"

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
