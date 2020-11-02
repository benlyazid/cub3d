/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 00:34:27 by kbenlyaz          #+#    #+#             */
/*   Updated: 2020/10/29 10:17:55 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

void	set_num(long n, int base, int fd)
{
	char	rtn;

	while (base > 0)
	{
		rtn = (n / base) + '0';
		n = n - ((n / base) * base);
		base /= 10;
		write(fd, &rtn, 1);
	}
}

void	fd_itoa(int n, int fd)
{
	float	base;
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		write(fd, "-", 1);
	}
	base = 1;
	while (nbr >= base)
	{
		base *= 10;
	}
	set_num(nbr, base / 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd > -1)
	{
		if (n == 0)
		{
			write(fd, "0", 1);
		}
		else
			fd_itoa(n, fd);
	}
}
