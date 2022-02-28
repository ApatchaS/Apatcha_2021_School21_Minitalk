/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:15:22 by asippy            #+#    #+#             */
/*   Updated: 2022/03/01 00:15:22 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/ft_printf_bonus.h"

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
