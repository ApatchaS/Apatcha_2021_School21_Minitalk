/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_ints_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:15:48 by asippy            #+#    #+#             */
/*   Updated: 2022/03/01 00:15:48 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/ft_printf_bonus.h"

int	ft_int_len(long int dec)
{
	int	len;

	len = 0;
	if (dec == 0)
		return (1);
	while (dec > 0)
	{
		dec /= 10;
		len++;
	}
	return (len);
}

void	ft_put_int(long int dec, int len)
{
	char	ch;

	if (len == 0)
		return ;
	if (dec < 10)
	{
		ch = dec + 48;
		write(1, &ch, 1);
		return ;
	}
	else
	{
		ft_put_int(dec / 10, len);
		ft_put_int(dec % 10, len);
	}
}
