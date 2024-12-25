/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:05:55 by mhoussas          #+#    #+#             */
/*   Updated: 2024/11/30 14:20:22 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_log16(size_t n)
{
	int	res;

	res = 0;
	while (n > 15)
	{
		res += 1;
		n /= 16;
	}
	return (res);
}

static size_t	ft_pow16(size_t n)
{
	size_t	res;

	res = 1;
	while (n--)
		res *= 16;
	return (res);
}

int	ft_putptr(void *ptr)
{
	int		count;
	char	*base;
	int		loop;
	size_t	n;

	n = (size_t) ptr;
	base = "0123456789abcdef";
	loop = ft_log16(n)+1;
	ft_putstr("0x");
	count = loop + 2;
	while (loop)
	{
		loop--;
		ft_putchar(base[n / ft_pow16(loop)]);
		n %= ft_pow16(loop);
	}
	return (count);
}
