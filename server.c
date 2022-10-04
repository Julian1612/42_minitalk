/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:16:06 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/04 18:05:48 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "server.h"
//Send X in Ascii
void test(int f)
{
	int		i;
	char	c;

	c = 0;
	i = 0;
	c |= 0x0 << i;
	i++;
	c |= 0x0 << i;
	i++;
	c |= 0x0 << i;
	i++;
	c |= 0x1 << i;
	i++;
	c |= 0x1 << i;
	i++;
	c |= 0x0 << i;
	i++;
	c |= 0x1 << i;
	i++;
	c |= 0x0 << i;
	(void) f;
	ft_printf("%c\n", c);
}

int main()
{
	int	pid;

	int i = 0;
	i++;
	pid = (int) getpid();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR2, &test);
	while (1)
	{
		usleep(1);
	}
}
