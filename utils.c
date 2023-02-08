/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:21:52 by dtunderm          #+#    #+#             */
/*   Updated: 2023/02/02 16:57:58 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	j = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = (str[i] - 48) + (k * 10);
		i++;
	}
	return (k * j);
}

int	ft_minnum(int num, int fd)
{
	num = 147483648;
	ft_putchar_fd('-', fd);
	ft_putchar_fd('2', fd);
	return (num);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	i;
	char	num[11];

	if (n == -2147483648)
		n = ft_minnum(n, fd);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	i = 0;
	while (n > 9)
	{
		num[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	num[i] = n + '0';
	while (i)
	{
		ft_putchar_fd(*(num + i), fd);
		i--;
	}
	ft_putchar_fd(*(num + 0), fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
