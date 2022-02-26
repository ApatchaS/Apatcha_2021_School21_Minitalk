/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:55:10 by asippy            #+#    #+#             */
/*   Updated: 2021/12/28 01:29:12 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_prefix(t_print *form, int sign)
{
	if (sign == -1)
	{
		write(1, "-", 1);
		return ;
	}
	if (form->plus_flag)
	{
		write(1, "+", 1);
		return ;
	}
	if (form->space_flag)
	{
		write(1, " ", 1);
		return ;
	}
}

static int	ft_out_signed_int(t_print *form, long int dec, int len, int sign)
{
	int	p;
	int	w;

	ft_w_and_p(form, len, &p, &w);
	if (!form->dash_flag && !(form->zero_flag && form->precision == -1))
		ft_fill(w, ' ');
	ft_prefix(form, sign);
	if (form->zero_flag && form->precision == -1)
		ft_fill(w, '0');
	else
		ft_fill(p, '0');
	ft_put_int(dec, len);
	if (form->dash_flag)
		ft_fill(w, ' ');
	if (sign == -1 || form->plus_flag || form->space_flag)
		return (w + p + len + 1);
	return (w + p + len);
}

int	ft_signed_int(t_print *form)
{
	long int	dec;
	int			sign;
	int			len;

	sign = 1;
	dec = va_arg(form->arg, int);
	if (dec < 0)
	{
		sign = -1;
		dec *= -1;
	}
	len = ft_int_len(dec);
	if (form->precision == 0 && dec == 0)
		len = 0;
	if (form->width != 0 && (sign == -1 || form->plus_flag || form->space_flag))
		form->width--;
	return (ft_out_signed_int(form, dec, len, sign));
}
