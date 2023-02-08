/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:21:55 by dtunderm          #+#    #+#             */
/*   Updated: 2023/02/06 17:27:56 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	count_len(long int c)
{
	int	i;

	i = 0;
	if (c <= 0)
	{
		i++;
		c = c * -1;
	}
	while (c > 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len;
	long	nb;

	len = count_len(n);
	nb = n;
	num = malloc(sizeof(char) * (len + 1));
	if (!(num))
		return (NULL);
	num[len--] = '\0';
	if (n < 0)
	{
		num[0] = '-';
		nb = nb * -1;
	}
	if (nb == 0)
		num[0] = '0';
	while (nb > 0)
	{
		num[len--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (num);
}

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

void	collect_bits(int bit)
{
	static int	i;
	static char	bits[8];

	if (bit == SIGUSR1)
		bits[i] = '1';
	else
		bits[i] = '0';
	i++;
	if (i == 8)
	{
		bits[i] = '\0';
		make_char(bits);
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "pid: ", 5);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, collect_bits);
		signal(SIGUSR2, collect_bits);
		pause();
	}
	return (0);
}
