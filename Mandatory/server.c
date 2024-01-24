/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:40:01 by skarim            #+#    #+#             */
/*   Updated: 2024/01/24 11:16:35 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handle_sig(int signal, siginfo_t *info, void *uap)
{
	static char	c = 0;
	static int	i = 0;
	static int	old_pid = 0;

	(void) uap;
	if (old_pid == 0)
		old_pid = info->si_pid;
	if (old_pid != info->si_pid)
	{
		c = 0;
		i = 0;
		old_pid = info->si_pid;
	}
	c = (c << 1) + (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		ft_putchar(c);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	sa.sa_sigaction = handle_sig;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(1);
	while (1)
	{
		pause();
	}
	return (0);
}
