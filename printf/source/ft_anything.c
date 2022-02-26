/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anything.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:52:23 by asippy            #+#    #+#             */
/*   Updated: 2021/12/27 15:55:36 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_anything(t_print *form, char ch)
{
	int	res;

	res = 1;
	if (form->width > res)
		res = form->width;
	ft_out_char_string(form, &ch, res, 1);
	return (res);
}
