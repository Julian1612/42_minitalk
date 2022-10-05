/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:16:14 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/05 21:31:04 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int main(int argc, char **argv)
{
	int	pid;

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
	pid = ft_atoi(argv[1]);
	send_message(argv[2], pid);
	return (0);
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
	send_bits(0, pid);
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
