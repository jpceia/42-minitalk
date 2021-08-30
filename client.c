/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:31:12 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/30 21:21:30 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"
#include <signal.h>
#include <stdio.h>
#include <stdbool.h>


static void	send_bit(pid_t pid, bool b)
{
	if (b)
	{
		if (kill(pid, SIGUSR1) < 0)
		{
			ft_putendl_fd("Error sending signal SIGUSR1 to server", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) < 0)
		{
			ft_putendl_fd("Error sending signal SIGUSR2 to server", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
	}
}

static void send_message(pid_t srv_pid, char *s)
{
	static pid_t	pid = 0;
	static int		nbits = 0;
	static char*	msg = NULL;

	if (srv_pid)
		pid = srv_pid;
	if (s)
	{
		msg = ft_strdup(s);
		nbits = 0;
	}
	send_bit(pid, msg[nbits / 8] >> ft_mod(-nbits, 8));
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
	struct sigaction sa;

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
