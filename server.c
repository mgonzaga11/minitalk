/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:10:46 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/11/08 15:54:54 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	fun(int sig_nal, siginfo_t *info, void *context)
{
	static char	number = 0;
	static int	i = 0;

	if (sig_nal == SIGUSR1)
		number = number | (1 << i);
	if (sig_nal == SIGUSR2)
		number = number | 0;
	i++;
	if (i == 8)
	{
		write(1, &number, 1);
		i = 0;
		number = 0;
	}
	kill(info->si_pid, SIGUSR1);
	(void)context;
}

int	main(void)
{
	struct sigaction	server_action;

	server_action.sa_handler = NULL;
	server_action.sa_sigaction = fun;
	sigemptyset(&server_action.sa_mask);
	server_action.sa_flags = SA_SIGINFO;
	ft_printf("%i\n", getpid());
	if (sigaction(SIGUSR1, &server_action, NULL))
		write(1, "Fail to use sigaction in SIGUSR1 signal.\n", 41);
	if (sigaction(SIGUSR2, &server_action, NULL))
		write(1, "Fail to use sigaction in SIGUSR2 signal.\n", 41);
	while (1)
		;
}
