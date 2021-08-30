/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 06:08:23 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/26 21:19:56 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*single_char_str(char *buf, char c)
{
	buf[0] = c;
	buf[1] = '\0';
	return (buf);
}

char	*ft_ulltoa(unsigned long long nb)
{
	int		index;
	char	*buf;

	buf = malloc(21);
	if (!buf)
		return (NULL);
	if (nb == 0)
		return (single_char_str(buf, '0'));
	index = 0;
	while (nb)
	{
		buf[index++] = '0' + nb % 10;
		nb /= 10;
	}
	buf[index] = '\0';
	return (ft_strreverse(buf));
}
