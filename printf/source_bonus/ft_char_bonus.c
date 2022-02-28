/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:14:54 by asippy            #+#    #+#             */
/*   Updated: 2022/03/01 00:14:54 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/ft_printf_bonus.h"

int	ft_char(t_print *form)
{
	int		res;
	char	ch;

	res = 1;
	ch = (char)va_arg(form->arg, int);
	if (form->width > res)
		res = form->width;
	ft_out_char_string(form, &ch, res, 1);
	return (res);
}
