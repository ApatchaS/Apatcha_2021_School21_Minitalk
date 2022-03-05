/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:19:53 by asippy            #+#    #+#             */
/*   Updated: 2022/03/05 19:17:42 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h> //functions: kill sigaction
# include <unistd.h> //functions: usleep pause
# include <stdlib.h> //functions: malloc free

int		ft_printf(const char *format, ...);

#endif