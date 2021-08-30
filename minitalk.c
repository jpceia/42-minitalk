/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:16:08 by jceia             #+#    #+#             */
/*   Updated: 2021/08/31 00:25:53 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft.h"
#include <stdlib.h>

void	set_sigusr(struct sigaction *sa)
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

void	send_bit(pid_t pid, bool b)
{
	if (b)
	{
		if (kill(pid, SIGUSR2) < 0)
		{
			ft_putendl_fd("Error sending signal SIGUSR2", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (kill(pid, SIGUSR1) < 0)
		{
			ft_putendl_fd("Error sending signal SIGUSR1", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
	}
}
