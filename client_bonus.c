/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurlani <nfurlani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:38:32 by nfurlani          #+#    #+#             */
/*   Updated: 2023/05/12 19:31:37 by nfurlani         ###   ########.fr       */
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

void	ft_sig(int sig, siginfo_t *si, void *s)
{
	(void)si;
	(void)s;
	if (SIGUSR1 == sig)
		write(1, "okay", 4);
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	s_struct;

	(void)argc;
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		ft_send(pid, argv[2][i]);
		i++;
	}
	ft_send(pid, '\0');
	sigemptyset(&s_struct.sa_mask);
	s_struct.sa_sigaction = ft_sig;
	s_struct.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_struct, NULL);
	pause();
}
