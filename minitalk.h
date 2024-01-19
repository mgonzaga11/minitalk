/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:32:31 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/11/08 15:34:49 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include "ft_printf.h"

# define I_CAN_SEND_SIGNAL 0
# define I_CANNOT_SEND_SIGNAL 1

void	received(int sig_nal, siginfo_t *info, void *context);
int		ft_atoi(const char *str);
void	kill_check(int pid, int signal);
void	send_sig(unsigned char *argv, char *pid_str);
void	fun(int sig_nal, siginfo_t *info, void *context);

#endif