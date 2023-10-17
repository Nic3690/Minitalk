/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:38:32 by nfurlani          #+#    #+#             */
/*   Updated: 2023/05/12 16:33:44 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "Libft/libft.h"

void	ft_send(int pid, unsigned int n)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if (n % 2 == 1)
			kill(pid, SIGUSR2);
		if (n % 2 == 0)
			kill(pid, SIGUSR1);
		usleep(100);
		n /= 2;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	(void)argc;
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		ft_send(pid, argv[2][i]);
		i++;
	}
}
