/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:11:03 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/11/08 15:58:50 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_glob_bit = I_CAN_SEND_SIGNAL;

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign = sign * -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

void	received(int sig_nal, siginfo_t *info, void *context)
{
	if (sig_nal == SIGUSR1)
		g_glob_bit = I_CAN_SEND_SIGNAL;
	(void)info;
	(void)context;
}

void	kill_check(int pid, int signal)
{
	if (kill(pid, signal))
	{
		write(1, "Error!\n", 7);
		exit(1);
	}
}

void	send_sig(unsigned char *argv, char *pid_str)
{
	int	i;
	int	moment_bit;
	int	bit;

	i = 0;
	while (argv[i] != '\0')
	{
		moment_bit = 0;
		while (moment_bit < 8)
		{
			if (g_glob_bit == I_CAN_SEND_SIGNAL)
			{
				g_glob_bit = I_CANNOT_SEND_SIGNAL;
				bit = argv[i] % 2;
				argv[i] = argv[i] / 2;
				if (bit == 1)
					kill_check(ft_atoi(pid_str), SIGUSR1);
				if (bit == 0)
					kill_check(ft_atoi(pid_str), SIGUSR2);
				moment_bit++;
			}
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	client_action;

	if (argc != 3)
		return (write(1, "Wrong number of arguments.\n", 28));
	if (ft_atoi(argv[1]) <= 0)
		return (write(1, "INVALID PID!\n", 13));
	client_action.sa_handler = NULL;
	client_action.sa_sigaction = received;
	client_action.sa_flags = 0;
	if (sigaction(SIGUSR1, &client_action, NULL))
		write(1, "Fail to use sigaction in SIGUSR1 signal.\n", 41);
	if (sigaction(SIGUSR2, &client_action, NULL))
		write(1, "Fail to use sigaction in SIGUSR2 signal.\n", 41);
	send_sig((unsigned char *)argv[2], argv[1]);
}
