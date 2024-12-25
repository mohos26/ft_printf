/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:05:37 by mhoussas          #+#    #+#             */
/*   Updated: 2024/12/03 08:58:24 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_log16(long n)
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

static int	ft_pow16(long n)
{
	int	res;

	res = 1;
	while (n--)
		res *= 16;
	return (res);
}

int	ft_puthex(long n, int aid)
{
	int		count;
	int		loop;
	char	base[16];

	if (aid)
		ft_memcpy(base, "0123456789ABCDEF", 16);
	else
		ft_memcpy(base, "0123456789abcdef", 16);
	count = 0;
	if (n < 0)
	{
		n = 4294967296 + n;
	}
	loop = ft_log16(n)+1;
	count += loop;
	while (loop)
	{
		loop--;
		ft_putchar(base[n / ft_pow16(loop)]);
		n %= ft_pow16(loop);
	}
	return (count);
}
