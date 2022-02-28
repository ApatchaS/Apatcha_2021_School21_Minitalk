/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anything_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:12:30 by asippy            #+#    #+#             */
/*   Updated: 2022/03/01 00:12:30 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/ft_printf_bonus.h"

int	ft_anything(t_print *form, char ch)
{
	int	res;

	res = 1;
	if (form->width > res)
		res = form->width;
	ft_out_char_string(form, &ch, res, 1);
	return (res);
}
