/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:16:14 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/06 11:45:53 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int main(int argc, char **argv)
{
	int	pid;
	struct sigaction	s_sigaction;

	if (argc < 3)
	{
		ft_printf("ERROR: Please enter the server PID and a message\n");
		return (1);
	}
	if (argc > 3)
	{
		ft_printf("ERROR: Too many arguments\n");
		return (1);
	}
	s_sigaction.sa_sigaction = received_confirmation;
	s_sigaction.sa_flags = SA_SIGINFO;
	pid = ft_atoi(argv[1]);
	sigaction(SIGUSR1, &s_sigaction, NULL);
	send_message(argv[2], pid);
	while (1)
		usleep(1);
	return (0);
}

void received_confirmation(int signal, siginfo_t *info, void *context)
{
	(void) signal;
	(void) info;
	(void) context;
	printf("Message has been received!\n");
	exit(0);
}

void	send_message(char *message, int pid)
{
	int	i;

	i = 0;
	while (i < (int) ft_strlen(message))
	{
		send_bits(message[i], pid);
		i++;
	}
	send_bits('\0', pid);
}

void	send_bits(char c, int pid)
{
	int	i;

	i = 7;
	while (i > -1)
	{
		usleep(100);
		if (((c >> i) & 0x1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
	}
}
