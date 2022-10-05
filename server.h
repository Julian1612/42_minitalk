/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:17:39 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/05 15:27:41 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include "./libft/libft.h"
//////////////////////
# include <stdio.h>
//////////////////////
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>

void receive_messages();
static void print_message(int signal, siginfo_t *info, void *context);

#endif
