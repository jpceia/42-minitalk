/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 01:13:34 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/24 01:14:41 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

#include <stdio.h>

void	handle_sigusr(int sig, siginfo_t *info, void *ucontext)
{
	static int				nbits = 0;
	static unsigned char	c = 0;

	(void)ucontext;
	if (sig != SIGUSR1 && sig != SIGUSR2)
		return ;
	nbits++;
	c <<= 1;
	if (sig == SIGUSR2)
		c++;
	if (nbits == 8)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		nbits = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa.sa_handler = 0;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = block_mask;
	sa.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	while (1)
		pause();
}
