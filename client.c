/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:31:12 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/30 20:25:36 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"
#include <signal.h>
#include <stdio.h>


/*
 * Client
 * takes two params
 *  1. Server PID
 *  2. Message to send
 */
int	main(int argc, char **argv)
{
	struct sigaction sa;
	int		sig;
	int		i;
	int		server_pid;
	char	*msg;

	if (argc != 3)
	{
		ft_putendl("This program requires two arguments:");
		ft_putendl("\t1. Server PID");
		ft_putendl("\t2. Message to send to the server");
		return (EXIT_FAILURE);
	}
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler =
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		msg = argv[2];
		while (*msg)
		{
			i = 8;
			while (i--)
			{
				usleep(10);
				if ((*msg >> i) & 1)
					sig = SIGUSR2;
				else
					sig = SIGUSR1;
				kill(server_pid, sig);
			}
			msg++;
		}
	}
	return (0);
}
