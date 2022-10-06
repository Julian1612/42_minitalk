/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:16:06 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/06 14:42:55 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	g_i = 7;

static void	print_message(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static char	c;

	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		bit = 0x0;
	if (signal == SIGUSR2)
		bit = 0x1;
	c |= bit << g_i;
	g_i--;
	if (g_i == -1)
	{
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		write(1, &c, 1);
		g_i = 7;
		c = 0x0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	s_sigaction;

	pid = (int) getpid();
	ft_printf("Server PID: %d\n", pid);
	s_sigaction.sa_sigaction = print_message;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
		pause();
	return (0);
}
