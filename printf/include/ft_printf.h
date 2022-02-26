/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:43:30 by asippy            #+#    #+#             */
/*   Updated: 2022/02/26 22:20:34 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_print
{
	va_list	arg;
	int		width;
	int		precision;
	int		dash_flag;
	int		zero_flag;
	int		grid_flag;
	int		plus_flag;
	int		space_flag;
}	t_print;

int		ft_char(t_print *form);
int		ft_string(t_print *form);
int		ft_pointer(t_print *form);
int		ft_signed_int(t_print *form);
int		ft_unsigned_int(t_print *form);
int		ft_hex(t_print *form, char ch);
int		ft_anything(t_print *form, char ch);
int		ft_str_len(char *str);
void	ft_fill(int count, char filler);
void	ft_out_char_string(t_print *form, void *src, int res, int len);
int		ft_convert_to_hex(unsigned long long dec, int tab[]);
void	ft_w_and_p(t_print *form, int len, int *p, int *w);
int		ft_out_pointer_hex(t_print *form, int tab[], int len, char ch);
int		ft_int_len(long int dec);
void	ft_put_int(long int dec, int len);

#endif