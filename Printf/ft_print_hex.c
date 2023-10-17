/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:58:10 by nfurlani          #+#    #+#             */
/*   Updated: 2023/02/10 11:06:13 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putunsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_putnbr(n / 10);
	len += ft_putchar(n % 10 + 48);
	return (len);
}

int	ft_puthex(unsigned long n, char *hex)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex((n / 16), hex);
	len += ft_putchar(hex[n % 16]);
	return (len);
}

int	ft_putpoint(unsigned long n, char *hex)
{
	int	len;

	len = 2;
	ft_putchar('0');
	ft_putchar('x');
	len += ft_puthex(n, hex);
	return (len);
}
