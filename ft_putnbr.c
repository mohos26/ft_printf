/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:47:43 by mhoussas          #+#    #+#             */
/*   Updated: 2024/11/30 14:42:11 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_log10(long n)
{
	int	res;

	res = 0;
	while (n > 9)
	{
		res += 1;
		n /= 10;
	}
	return (res);
}

int	ft_pow10(long n)
{
	long	res;

	res = 1;
	while (n--)
		res *= 10;
	return (res);
}

long	ft_putnbr(long n)
{
	int	loop;
	int	pow;
	int	len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	loop = ft_log10(n);
	while (loop + 1)
	{
		pow = ft_pow10(loop);
		len += ft_putchar(n / pow + 48);
		n %= pow;
		loop--;
	}
	return (len);
}
