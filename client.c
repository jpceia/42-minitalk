/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:31:12 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/31 00:29:27 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"
#include <signal.h>
#include <stdbool.h>

static void	send_message(pid_t target_pid, char *s)
{
	static pid_t	pid = 0;
	static int		nbits = 0;
	static int		len = 0;
	static char		*msg = NULL;

	if (target_pid)
		pid = target_pid;
	if (s)
	{
		msg = ft_strdup(s);
		len = ft_strlen(s);
		nbits = 0;
	}
	if (nbits / 8 < len)
		send_bit(pid, (msg[nbits / 8] >> (7 - ft_mod(nbits, 8))) & 1);
	else
	{
		if (msg)
		{
			free(msg);
			msg = NULL;
		}
		send_bit(pid, 0);
	}
	nbits++;
}

static void	handle_cli_sigusr(int sig)
{
	if (sig == SIGUSR1)
		send_message(0, 0);
	else if (sig == SIGUSR2)
		exit(EXIT_SUCCESS);
}

/*
 * Client
 * takes two params
 *  1. Server PID
 *  2. Message to send
 */
int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_putendl("This program requires two arguments:");
		ft_putendl("\t1. Server PID");
		ft_putendl("\t2. Message to send to the server");
		return (EXIT_FAILURE);
	}
	ft_bzero(&sa, sizeof(sa));
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = handle_cli_sigusr;
	set_sigusr(&sa);
	send_message(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
