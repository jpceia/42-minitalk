/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 01:13:34 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/30 20:25:51 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"
#include <signal.h>
#include <stdio.h>

void	handle_sigusr(int sig, siginfo_t *info, void *ucontext)
{
	static int	nbits = 0;
	static char	c = 0;
	static char	*msg = NULL;

	(void)ucontext;
	if (sig != SIGUSR1 && sig != SIGUSR2)
		return ;
	c <<= 1;
	if (sig == SIGUSR2)
		c++;
	if (++nbits % 8 == 0)
	{
		if (c)
			msg = ft_straddc(msg, c);
		else
		{
			ft_putstr(msg);
			free(msg);
		}
		c = 0;
	}
}

static void	set_sigusr(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) < 0)
	{
		ft_putendl("Failed to setup SIGUSR1 handler");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, sa, NULL) < 0)
	{
		ft_putendl("Failed to setup SIGUSR2 handler");
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
	sa.sa_sigaction = handle_sigusr;
	set_sigusr(&sa);
	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
