/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hexs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:37:04 by asippy            #+#    #+#             */
/*   Updated: 2021/12/28 00:16:11 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_convert_to_hex(unsigned long long dec, int tab[])
{
	int	len;

	if (dec == 0)
	{
		tab[0] = 0;
		return (1);
	}
	len = 0;
	while (dec > 0)
	{
		tab[len++] = dec % 16;
		dec /= 16;
	}
	return (len);
}

void	ft_w_and_p(t_print *form, int len, int *p, int *w)
{
	int	tmp_p;
	int	tmp_w;

	tmp_p = 0;
	tmp_w = 0;
	if (form->precision > len)
		tmp_p = form->precision - len;
	if (form->width > len + tmp_p)
		tmp_w = form->width - len - tmp_p;
	*p = tmp_p;
	*w = tmp_w;
	return ;
}

static char	*ft_grid(t_print *form, int tab, int len, char ch)
{
	if (ch != 'p' && (!form->grid_flag || (tab == 0 && len == 1)))
		return ("");
	if (form->width > 2)
		form->width -= 2;
	else
		form->width = 0;
	if (ch == 'X')
		return ("0X");
	return ("0x");
}

static void	ft_put_hex(int tab[], int len, char ch)
{
	char	*base;
	int		iter;

	if (ch == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	iter = len - 1;
	while (iter >= 0)
	{
		write(1, &base[tab[iter]], 1);
		iter--;
	}
	return ;
}

int	ft_out_pointer_hex(t_print *form, int tab[], int len, char ch)
{
	int		p;
	int		w;
	char	*gr;

	gr = ft_grid(form, tab[0], len, ch);
	ft_w_and_p(form, len, &p, &w);
	if (!form->dash_flag && !(form->zero_flag && form->precision == -1))
		ft_fill(w, ' ');
	write(1, gr, ft_str_len(gr));
	if (form->zero_flag && form->precision == -1)
		ft_fill(w, '0');
	else
		ft_fill(p, '0');
	ft_put_hex(tab, len, ch);
	if (form->dash_flag)
		ft_fill(w, ' ');
	return (p + w + len + ft_str_len(gr));
}
