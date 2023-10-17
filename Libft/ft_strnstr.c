/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:17:13 by nfurlani          #+#    #+#             */
/*   Updated: 2023/02/08 17:55:54 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!haystack && !n)
		return (0);
	while (needle[len] != '\0')
		len++;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < n)
	{
		if (haystack[i] == needle[0])
		{
			if ((len + i <= n) && !ft_strncmp((haystack + i), needle, len))
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
