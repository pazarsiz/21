/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:13:37 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/03 12:14:52 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"
#include "minitalk.h"

void	warning(void)
{
	write(1, "The programm needs three arguments:\n", 36);
	write(1, "./client\t PID\t The message\n", 27);
	exit(0);
}

void	char_sender(int pid, unsigned char byte)
{
	int	counter;

	counter = 64;
	while (counter)
	{
		if (byte & counter)
		{
			if (kill(pid, SIGUSR1) == -1)
				error("Check PID, please\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error("Check PID, please\n");
		}
		counter >>= 1;
		usleep(600);
	}
}

void	message_sender(char *str_pid, char *message)
{
	int			pid;

	pid = ft_atoi(str_pid);
	while (*message)
	{
		char_sender(pid, *message);
		++message;
	}
	char_sender(pid, *message);
}

void	success(int sig)
{
	(void)sig;
	write(1, "The message was successfully received by server.\n", 49);
	exit(0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		warning();
	signal(SIGUSR1, success);
	message_sender(argv[1], argv[2]);
	while (1)
		pause();
	return (0);
}
