/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:31:12 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/24 01:16:07 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include "libft.h"

/*
 * Client
 * takes two params
 *  1. Server PID
 *  2. Message to send
 */
int	main(int argc, char **argv)
{
	int		sig;
	int		i;
	int		server_pid;
	char	*msg;

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
