/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jceia <jceia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:49:11 by jceia             #+#    #+#             */
/*   Updated: 2021/08/27 18:49:32 by jceia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_mod(int x, int y)
{
	int	r;

	r = x % y;
	if (r < 0)
		return (r + y);
	return (r);
}
