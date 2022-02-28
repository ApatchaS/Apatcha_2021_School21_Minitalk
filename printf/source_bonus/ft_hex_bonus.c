/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:15:06 by asippy            #+#    #+#             */
/*   Updated: 2022/03/01 00:15:06 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/ft_printf_bonus.h"

int	ft_hex(t_print *form, char ch)
{
	unsigned int	dec;
	int				tab[8];
	int				len;

	dec = va_arg(form->arg, unsigned int);
	len = ft_convert_to_hex(dec, tab);
	if (form->precision == 0 && len == 1 && tab[0] == 0)
		len = 0;
	return (ft_out_pointer_hex(form, tab, len, ch));
}
