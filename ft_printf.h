/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:14:23 by mhoussas          #+#    #+#             */
/*   Updated: 2024/12/03 09:13:24 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_printf(const char *s, ...);
int		ft_puthex(long n, int aid);
int		ft_putptr(void *ptr);
int		ft_putchar(char c);
int		ft_putstr(char *s);
long	ft_putnbr(long n);

#endif
