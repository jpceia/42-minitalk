/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:16:08 by jceia             #+#    #+#             */
/*   Updated: 2021/08/30 21:21:09 by jceia            ###   ########.fr       */
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
