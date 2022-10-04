/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:16:14 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/04 18:10:37 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int main(int argc, char **argv)
{
	(void) argc;
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
	// kill(ft_atoi(argv[1]), SIGUSR2);
	// send_message(argv[2]);
	return (0);
}

// void	send_message(char *message)
// {
// 	int	i;

// 	i = 0;
// 	printf("%s", message);
// 	while (i < ft_strlen(message))
// 	{

// 	}

// }
