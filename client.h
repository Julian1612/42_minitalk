/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:16:39 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/04 20:34:56 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include "./libft/libft.h"
//////////////////////////
# include <stdio.h>
//////////////////////////

void	send_message(char *message, int pid);
void	send_bits(char c, int pid);

#endif
