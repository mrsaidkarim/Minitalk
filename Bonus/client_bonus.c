/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:12:41 by skarim            #+#    #+#             */
/*   Updated: 2024/01/24 16:10:38 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_check_args(int ac, char **av)
{
	if (ac != 3)
		ft_error_msg("Invalid arguments!");
	return (ft_atoi(av[1]));
}

void	ft_send_char(char c, int pid)
{
	int	shift_number;

	shift_number = 7;
	while (shift_number >= 0)
	{
		if ((c >> shift_number) % 2 != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error_msg("send a message fails!");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error_msg("send a message fails!");
		}
		usleep(500);
		shift_number--;
	}
}

void	handle_sig(int signal)
{
	if (signal == SIGUSR1)
		write(1, "The message recieved!\n", 22);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	pid = ft_check_args(ac, av);
	if (pid <= 0)
		ft_error_msg("Invalid pid!");
	if (av[2][0] == '\0')
		ft_error_msg("The message is empty!");
	signal(SIGUSR1, &handle_sig);
	i = 0;
	while (av[2][i])
	{
		ft_send_char(av[2][i], pid);
		i++;
	}
	ft_send_char('\0', pid);
	return (0);
}
