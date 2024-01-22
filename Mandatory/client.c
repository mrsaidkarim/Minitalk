/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:39:43 by skarim            #+#    #+#             */
/*   Updated: 2024/01/22 22:24:36 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_check_args(int ac, char **av)
{

	if (ac != 3)
		ft_error_msg("Too many arguments!");
	return (ft_atoi(av[1]));
}

void	ft_send_message(char *msg, int pid)
{
	int	i;
	int	shift_nbr;
	
	i = 0;
	if (msg[0] == '\0')
		ft_error_msg("The message is empty!");
	while (msg[i])
	{
		shift_nbr = 7;
		while (shift_nbr >= 0)
		{
			if ((msg[i] >> shift_nbr) % 2 != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(500);
			shift_nbr--;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	pid = ft_check_args(ac, av);
	if (pid == -1 || pid == 0)
		ft_error_msg("Invalid pid!");
	ft_send_message(av[2], pid);
	return (0);
}
