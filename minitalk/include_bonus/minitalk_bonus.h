/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:17:17 by asippy            #+#    #+#             */
/*   Updated: 2022/03/01 00:17:17 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h> //functions: kill sigaction
# include <unistd.h> //functions: usleep pause
# include <stdlib.h> //functions: malloc free

int		ft_printf(const char *format, ...);

#endif