/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asippy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:19:07 by asippy            #+#    #+#             */
/*   Updated: 2022/03/01 00:19:07 by asippy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minitalk_bonus.h"

static int	ft_get_message(int sig, char *str)
{
	int				message_legnth;
	static size_t	iter;
	static size_t	buf;
	static size_t	pos;

	message_legnth = -1;
	if (sig == SIGUSR1)
		buf = (buf | (1 << iter));
	iter++;
	if (iter == 8)
	{
		str[pos++] = buf;
		iter = 0;
		buf = 0;
		if (str[pos - 1] == '\0')
		{
			ft_printf("%s\n", str);
			message_legnth = 0;
			pos = 0;
			free(str);
		}
	}
	return (message_legnth);
}

static int	ft_get_message_length(int sig)
{
	int				message_legnth;
	static size_t	iter;
	static size_t	buf;

	message_legnth = 0;
	if (sig == SIGUSR1)
		buf = (buf | (1 << iter));
	iter++;
	if (iter == 32)
	{
		message_legnth = buf;
		iter = 0;
		buf = 0;
	}
	return (message_legnth);
}

static void	ft_recieve_message(int sig, siginfo_t *act, void *oldact)
{
	static int		message_legnth;
	static char		*str;

	(void) act;
	(void) oldact;
	if (message_legnth == 0)
		message_legnth = ft_get_message_length(sig);
	if (message_legnth < 0)
		message_legnth = ft_get_message(sig, str);
	if (message_legnth > 0)
	{
		str = malloc(sizeof(char) * (message_legnth + 1));
		if (str == (void *)0)
			return ;
		message_legnth = -1;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	pid = getpid();
	ft_printf("The server's PID: %d\n", pid);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = ft_recieve_message;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause ();
	return (0);
}
