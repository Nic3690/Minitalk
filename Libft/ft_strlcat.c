/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:32:37 by nfurlani          #+#    #+#             */
/*   Updated: 2023/02/06 18:30:37 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	j;
	size_t	i;
	size_t	lend;
	size_t	lens;

	j = 0;
	i = 0;
	lend = 0;
	lens = 0;
	while (src[lens] != '\0')
		lens++;
	if ((!dst && !src) || !n)
		return (lens);
	if (n < ft_strlen(dst))
		return (lens + n);
	while (dst[lend] != '\0')
		lend++;
	if (!n)
		return (lens);
	while (dst[i] != '\0' && !(dst[0] == '\0'))
		i++;
	while (src[j] != '\0' && (i < n - 1))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (lend + lens);
}
