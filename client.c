/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:21:49 by dtunderm          #+#    #+#             */
/*   Updated: 2023/02/02 16:59:01 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	make_char(char *bits)
{
	int	i;
	int	multiplier;
	int	total;

	i = 0;
	total = 0;
	multiplier = 1;
	while (bits[i])
	{
		if (bits[i] == '1')
			total = total + (multiplier * 1);
		multiplier = multiplier * 2;
		i++;
	}
	write(1, &total, 1);
}

void	bit_conv(char c, int PID)
{
	int	j;
	int	i;

	j = 0;
	while (j < 8)
	{
		i = ((c >> j) & 1);
		if (i != 0)
			kill(PID, SIGUSR1);
		else
			kill(PID, SIGUSR2);
		usleep(300);
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		write(1, "ERROR\n", 7);
		exit(0);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
		{
			bit_conv(argv[2][i], pid);
			i++;
		}
		write(1, "pid: ", 5);
		ft_putnbr_fd(pid, 1);
		write(1, "\n", 1);
	}
	return (0);
}
