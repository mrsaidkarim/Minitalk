/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:30:13 by skarim            #+#    #+#             */
/*   Updated: 2024/01/21 21:35:54 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_error_msg(char *str)
{
	write(1, "Error:\n", 7);
	write(1, str, ft_strlen(str));
	exit(1);
}

int	ft_atoi(char *str)
{
	long	nbr;

	nbr = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	if (nbr > 2147483647)
		return (-1);
	return (nbr);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
}
