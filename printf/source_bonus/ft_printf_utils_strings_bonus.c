/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_strings_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:15:55 by asippy            #+#    #+#             */
/*   Updated: 2022/03/01 00:15:55 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/ft_printf_bonus.h"

int	ft_str_len(char *str)
{
	int	res;

	res = 0;
	while (str[res] != '\0')
		res++;
	return (res);
}

void	ft_fill(int count, char filler)
{
	int	i;

	i = 0;
	while (i < count)
	{
		write(1, &filler, 1);
		i++;
	}
	return ;
}

void	ft_out_char_string(t_print *form, void *src, int res, int len)
{
	if (form->dash_flag)
		write(1, src, len);
	if (!form->dash_flag && form->zero_flag)
		ft_fill(res - len, '0');
	else
		ft_fill(res - len, ' ');
	if (!form->dash_flag)
		write(1, src, len);
	return ;
}
