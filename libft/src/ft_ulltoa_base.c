/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpceia <jpceia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 06:30:12 by jpceia            #+#    #+#             */
/*   Updated: 2021/08/26 21:20:03 by jpceia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*single_char_str(char *buf, char c)
{
	buf[0] = c;
	buf[1] = '\0';
	return (buf);
}

char	*ft_ulltoa_base(unsigned long long nb, const char *base)
{
	int		base_size;
	int		index;
	char	*buf;

	base_size = ft_strlen(base);
	if (base_size <= 1)
		return (NULL);
	buf = malloc(64);
	if (!buf)
		return (NULL);
	if (nb == 0)
		return (single_char_str(buf, base[0]));
	index = 0;
	while (nb)
	{
		buf[index++] = base[nb % base_size];
		nb /= base_size;
	}
	buf[index] = '\0';
	return (ft_strreverse(buf));
}
