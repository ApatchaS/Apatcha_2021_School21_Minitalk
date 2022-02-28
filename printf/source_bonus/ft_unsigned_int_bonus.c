/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:16:16 by asippy            #+#    #+#             */
/*   Updated: 2022/03/01 00:16:16 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/ft_printf_bonus.h"

static int	ft_out_unsigned_int(t_print *form, unsigned int dec, int len)
{
	int	p;
	int	w;

	ft_w_and_p(form, len, &p, &w);
	if (!form->dash_flag && !(form->zero_flag && form->precision == -1))
		ft_fill(w, ' ');
	if (form->zero_flag && form->precision == -1)
		ft_fill(w, '0');
	else
		ft_fill(p, '0');
	ft_put_int(dec, len);
	if (form->dash_flag)
		ft_fill(w, ' ');
	return (w + p + len);
}

int	ft_unsigned_int(t_print *form)
{
	unsigned int	dec;
	int				len;

	dec = va_arg(form->arg, unsigned int);
	len = ft_int_len(dec);
	if (form->precision == 0 && dec == 0)
		len = 0;
	return (ft_out_unsigned_int(form, dec, len));
}
