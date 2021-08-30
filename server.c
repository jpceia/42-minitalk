/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 01:13:34 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/31 00:29:22 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"
#include <signal.h>

static void	handle_srv_sigusr(int sig, siginfo_t *info, void *ucontext)
{
	static int		nbits = 0;
	static char		c = 0;
	static char		*msg = NULL;

	(void)ucontext;
	if (!msg)
		msg = ft_empty_string();
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
			msg = NULL;
			send_bit(info->si_pid, true);
			return ;
		}
		c = 0;
	}
	send_bit(info->si_pid, false);
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
