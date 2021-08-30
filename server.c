/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 01:13:34 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/30 21:48:47 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"
#include <signal.h>
#include <stdio.h>

static void	handle_srv_sigusr(int sig, siginfo_t *info, void *ucontext)
{
	static pid_t	pid;
	static int		nbits = 0;
	static char		c = 0;
	static char		*msg = NULL;

	(void)ucontext;

	if (info->si_pid)
	{
		ft_putstr("Updated pid: ");
		ft_putnbr(info->si_pid);
		ft_putchar('\n');
		pid = info->si_pid;
	}
	if (sig != SIGUSR1 && sig != SIGUSR2)
		return ;
	c <<= 1;
	if (sig == SIGUSR2)
		c++;
	ft_putstr("Received signal: ");
	ft_putnbr(sig);
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar('\n');
	if (++nbits % 8 == 0)
	{
		if (c)
			msg = ft_straddc(msg, c);
		else
		{
			ft_putstr(msg);
			free(msg);
			if (kill(pid, SIGUSR2) < 0)
			{
				ft_putendl_fd("Error sending SIGUSR2 signal to client", STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
			return ;
		}
		c = 0;
	}
	if (kill(pid, SIGUSR1) < 0)
	{
		ft_putendl_fd("Error sending SIGUSR1 signal to client", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGINT);
	sigaddset(&sa.sa_mask, SIGQUIT);
	sa.sa_handler = 0;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_srv_sigusr;
	set_sigusr(&sa);
	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
