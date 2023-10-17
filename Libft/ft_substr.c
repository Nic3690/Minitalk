/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:04:22 by nfurlani          #+#    #+#             */
/*   Updated: 2023/02/07 19:51:19 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_superlen(int len, int len2)
{
	char	*sub;

	if (len2 < len)
		sub = (char *)malloc(sizeof(char) * (len2 + 1));
	else
		sub = (char *)malloc(sizeof(char) * (len + 1));
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len2;
	int		n;
	int		i;
	int		j;

	len2 = 1;
	n = start;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	while (s[start++] != '\0')
		len2++;
	sub = ft_superlen(len, len2);
	if (!sub)
		return (NULL);
	j = n;
	while (s[n] != '\0' && (size_t)n < len + j)
		sub[i++] = s[n++];
	sub[i] = '\0';
	return (sub);
}
