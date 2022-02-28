/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:15:30 by asippy            #+#    #+#             */
/*   Updated: 2022/03/01 00:15:30 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/ft_printf_bonus.h"

static void	ft_init_form(t_print *form)
{
	form->width = 0;
	form->precision = -1;
	form->dash_flag = 0;
	form->zero_flag = 0;
	form->grid_flag = 0;
	form->plus_flag = 0;
	form->space_flag = 0;
	return ;
}

static void	ft_flag_process(const char *f, size_t *i, t_print *form)
{
	while (f[*i] == '-' || f[*i] == '0' || f[*i] == '#'
		|| f[*i] == '+' || f[*i] == ' ')
	{
		if (f[*i] == '-')
			form->dash_flag = 1;
		if (f[*i] == '0')
			form->zero_flag = 1;
		if (f[*i] == '#')
			form->grid_flag = 1;
		if (f[*i] == '+')
			form->plus_flag = 1;
		if (f[*i] == ' ')
			form->space_flag = 1;
		(*i)++;
	}
	return ;
}

static void	ft_wid_pre_process(const char *f, size_t *i, int *res, int flag)
{
	int	result;

	result = 0;
	if (flag)
	{
		if (f[*i] == '.')
		{
			while (f[*i] == '.')
				(*i)++;
		}
		else
			return ;
	}
	while (f[*i] >= '0' && f[*i] <= '9')
	{
		result = 10 * result + (f[*i] - 48);
		(*i)++;
	}
	*res = result;
	return ;
}

static int	ft_process(const char *format, size_t *iter, t_print *form)
{
	int	res;

	res = 0;
	(*iter)++;
	ft_flag_process(format, iter, form);
	ft_wid_pre_process(format, iter, &form->width, 0);
	ft_wid_pre_process(format, iter, &form->precision, 1);
	if (format[*iter] == '\0')
		return (res);
	else if (format[*iter] == 'c')
		res = ft_char(form);
	else if (format[*iter] == 's')
		res = ft_string(form);
	else if (format[*iter] == 'p')
		res = ft_pointer(form);
	else if (format[*iter] == 'd' || format[*iter] == 'i')
		res = ft_signed_int(form);
	else if (format[*iter] == 'u')
		res = ft_unsigned_int(form);
	else if (format[*iter] == 'x' || format[*iter] == 'X')
		res = ft_hex(form, format[*iter]);
	else
		res = ft_anything(form, format[*iter]);
	(*iter)++;
	return (res);
}

int	ft_printf(const char *format, ...)
{
	t_print	*form;
	size_t	iter;
	int		res;

	iter = 0;
	res = 0;
	if (format == (void *)0)
		return (-1);
	form = (t_print *)malloc(sizeof(t_print));
	if (form == (void *)0)
		return (-1);
	va_start(form->arg, format);
	while (format[iter] != '\0')
	{
		if (format[iter] == '%')
		{
			ft_init_form(form);
			res += ft_process(format, &iter, form);
			continue ;
		}
		res += write(1, &format[iter++], 1);
	}
	va_end(form->arg);
	free(form);
	return (res);
}
