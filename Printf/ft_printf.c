/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:50:43 by nfurlani          #+#    #+#             */
/*   Updated: 2023/02/10 11:03:33 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar_print(const char *str, int i, va_list arg)
{
	int	len;

	len = 0;
	if (str[i + 1] == 'c')
		len += ft_putchar((char)(va_arg(arg, int)));
	else if (str[i + 1] == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (str[i + 1] == 'p')
		len += ft_putpoint(va_arg(arg, unsigned long), "0123456789abcdef");
	else if (str[i + 1] == 'd')
		len += ft_putnbr(va_arg(arg, int));
	else if (str[i + 1] == 'i')
		len += ft_putnbr(va_arg(arg, int));
	else if (str[i + 1] == 'u')
		len += ft_putunsigned(va_arg(arg, unsigned int));
	else if (str[i + 1] == 'x')
		len += ft_puthex(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (str[i + 1] == 'X')
		len += ft_puthex(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (str[i + 1] == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	if (!str)
		return (0);
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += ft_putchar_print(str, i, arg);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}

// int main()
// {
// 	int c = 10;
// 	printf("%x\n", c);
// 	ft_printf("%x\n", ft_printf("%x\n", c));
// }