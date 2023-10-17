/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:41:25 by nfurlani          #+#    #+#             */
/*   Updated: 2023/01/26 20:22:27 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		n;
	int		len1;
	int		len2;

	i = -1;
	n = 0;
	len1 = 0;
	len2 = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;
	str = malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[n] != '\0')
		str[i++] = s2[n++];
	str[i] = '\0';
	return (str);
}
