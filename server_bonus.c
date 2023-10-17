/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:05:18 by nfurlani          #+#    #+#             */
/*   Updated: 2023/05/12 19:35:31 by nfurlani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "Printf/ft_printf.h"

int	ft_power(int e)
{
	int	n;

	n = 1;
	while (e > 0)
	{
		n *= 2;
		e--;
	}
	return (n);
}

void	ft_signal(int sig, siginfo_t *si, void *s)
{
	static int	i;
	static int	n;
	int			pid;

	(void)s;
	pid = si->si_pid;
	if (SIGUSR2 == sig)
		n += ft_power(i);
	i++;
	if (n == '\0' && i == 8)
	{
		usleep(1000);
		kill(pid, SIGUSR1);
	}
	if (i == 8)
	{
		ft_printf("%c", n);
		i = 0;
		n = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	s_struct;

	sigemptyset(&s_struct.sa_mask);
	pid = getpid();
	ft_printf("%d", pid);
	s_struct.sa_sigaction = ft_signal;
	s_struct.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_struct, NULL);
	sigaction(SIGUSR2, &s_struct, NULL);
	while (1)
		pause();
}
