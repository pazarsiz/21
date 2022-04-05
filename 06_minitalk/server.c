/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbungo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:18:13 by wbungo            #+#    #+#             */
/*   Updated: 2022/03/03 12:20:16 by wbungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "./libft/libft.h"

void	pid_printer(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(1, "PID: ", 5);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
}

void	one_bit_handler(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	(void)info;
	if (!g_message.bit)
	{
		g_message.bit = 64;
		++(g_message.byte);
	}
	g_message.message[g_message.byte] += g_message.bit;
	g_message.bit >>= 1;
	if (g_message.byte == BUFFSIZE - 2 && !g_message.bit)
		g_message.buff_overflow = TRUE;
}

void	zero_bit_handler(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (!g_message.bit)
	{
		g_message.bit = 64;
		++(g_message.byte);
	}
	g_message.bit >>= 1;
	if (g_message.byte == BUFFSIZE - 2 && !g_message.bit)
		g_message.buff_overflow = TRUE;
	else if (!g_message.message[g_message.byte] && !g_message.bit)
	{
		g_message.received = TRUE;
		kill(info->si_pid, SIGUSR1);
	}
}

bool	message_handler(void)
{
	while (1)
	{
		pause();
		if (g_message.received || g_message.buff_overflow)
		{
			write(1, g_message.message, ft_strlen(g_message.message));
			ft_bzero(g_message.message, BUFFSIZE);
			g_message.bit = 64;
			g_message.byte = 0;
			if (g_message.received)
				write(1, "\n", 1);
			g_message.received = FALSE;
			g_message.buff_overflow = FALSE;
		}
	}
	return (TRUE);
}

int	main(void)
{
	struct sigaction	sigusr1_handler;
	struct sigaction	sigusr2_handler;

	sigusr1_handler.sa_flags = SA_SIGINFO;
	sigusr1_handler.sa_sigaction = one_bit_handler;
	sigusr2_handler.sa_flags = SA_SIGINFO;
	sigusr2_handler.sa_sigaction = zero_bit_handler;
	if (sigaction(SIGUSR1, &sigusr1_handler, NULL) != 0)
		error("signal error\n");
	if (sigaction(SIGUSR2, &sigusr2_handler, NULL) != 0)
		error("signal error\n");
	pid_printer();
	ft_bzero(g_message.message, BUFFSIZE);
	message_handler();
}
