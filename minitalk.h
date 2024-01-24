/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:16:11 by skarim            #+#    #+#             */
/*   Updated: 2024/01/24 19:02:03 by skarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

int		ft_strlen(char *str);
void	ft_error_msg(char *str);
int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);

#endif