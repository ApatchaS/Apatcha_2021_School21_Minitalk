/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:54:56 by asippy            #+#    #+#             */
/*   Updated: 2021/12/28 01:26:19 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_pointer(t_print *form)
{
	unsigned long long	dec;
	int					tab[16];
	int					len;

	dec = (unsigned long long)va_arg(form->arg, void *);
	len = ft_convert_to_hex(dec, tab);
	if (form->precision == 0 && len == 1 && tab[0] == 0)
		len = 0;
	return (ft_out_pointer_hex(form, tab, len, 'p'));
}
