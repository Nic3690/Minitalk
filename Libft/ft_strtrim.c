/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:19:48 by nfurlani          #+#    #+#             */
/*   Updated: 2023/02/08 18:14:09 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	chartofind(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_start(const char *s1, const char *set)
{
	int	start;
	int	n;

	n = 0;
	start = 0;
	while (s1[n] != '\0')
	{
		if (!chartofind(set, s1[n]))
		{
			start = n;
			break ;
		}
		n++;
	}
	return (n);
}

int	ft_end(const char *s1, const char *set)
{
	int	end;
	int	n;

	end = 0;
	n = 0;
	while (s1[n] != '\0')
		n++;
	n--;
	while (n >= 0)
	{
		if (!chartofind(set, s1[n]))
		{
			end = n;
			break ;
		}
		n--;
	}
	return (end + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		n;
	int		start;
	int		end;

	n = 0;
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	str = (char *)(malloc((end - start + 1) * sizeof(char)));
	if (!str)
		return (0);
	n = 0;
	while (start < end)
	{
		str[n++] = s1[start];
		start++;
	}
	str[n] = '\0';
	return (str);
}
