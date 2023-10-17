/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:21:48 by nfurlani          #+#    #+#             */
/*   Updated: 2023/02/06 18:02:59 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str1;
	char	*s2;
	char	*head;

	str1 = (char *)s1;
	len = 0;
	while (str1[len] != '\0')
		len++;
	s2 = malloc((len * sizeof(char)) + 1);
	if (s2 == 0)
		return (0);
	head = s2;
	while (*str1 != '\0')
	{
		*s2 = *str1;
		s2++;
		str1++;
	}
	*s2 = '\0';
	return (head);
}
