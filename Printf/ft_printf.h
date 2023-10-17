/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:50:12 by nfurlani          #+#    #+#             */
/*   Updated: 2023/02/10 11:06:20 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <fcntl.h>
# include <ctype.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar_print(const char *str, int i, va_list arg);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putunsigned(unsigned int n);
int	ft_puthex(unsigned long n, char *hex);
int	ft_putpoint(unsigned long n, char *hex);

#endif