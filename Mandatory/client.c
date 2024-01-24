/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:39:43 by skarim            #+#    #+#             */
/*   Updated: 2024/01/24 16:10:17 by skarim           ###   ########.fr       */
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

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	pid = ft_check_args(ac, av);
	if (pid <= 0)
		ft_error_msg("Invalid pid!");
	if (av[2][0] == '\0')
		ft_error_msg("The message is empty!");
	i = 0;
	while (av[2][i])
	{
		ft_send_char(av[2][i], pid);
		i++;
	}
	return (0);
}
