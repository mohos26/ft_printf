/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:14:42 by mhoussas          #+#    #+#             */
/*   Updated: 2024/12/02 17:46:53 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	aid(char c, va_list args)
{
	int	count;

	if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'x' || c == 'X')
		count = ft_puthex(va_arg(args, int), c == 'X');
	else if (c == 'p')
		count = ft_putptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count = ft_putnbr(va_arg(args, unsigned int));
	else if (c == '%')
		count = ft_putchar('%');
	else
		count = ft_putchar(c);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	if (write(1, "", 0) < 0)
		return (-1);
	va_start(args, s);
	count = 0;
	while (s && *s)
	{
		if (*s == '%')
			count += aid(*++s, args);
		else
			count += ft_putchar(*s);
		s++;
	}
	va_end(args);
	return (count);
}
