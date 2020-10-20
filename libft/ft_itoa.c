/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:09:32 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/18 03:05:42 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*set_number(long n, int sighn, int i, int base)
{
	char	*rtn;
	int		index;

	index = 0;
	if (sighn == 1)
	{
		if (NULL == (rtn = malloc(sizeof(char) * (i + 2))))
			return (0);
		rtn[0] = '-';
	}
	if (sighn == 0)
		if (NULL == (rtn = malloc(sizeof(char) * i + 1)))
			return (0);
	while (base > 0)
	{
		if (sighn == 1)
			rtn[index + 1] = (n / base) + '0';
		else
			rtn[index] = (n / base) + '0';
		n = n - ((n / base) * base);
		base /= 10;
		index++;
	}
	rtn[index + sighn] = '\0';
	return (rtn);
}

char	*errore(void)
{
	char	*errore;

	if (NULL == (errore = malloc(sizeof(char) * 2)))
		return (0);
	errore[0] = '0';
	errore[1] = '\0';
	return (errore);
}

char	*ft_itoa(int n)
{
	int		i;
	double	base;
	int		sighn;
	long	nbr;

	sighn = 0;
	nbr = n;
	if (nbr == 0 || nbr < (int)-2147483648)
		return (errore());
	if (nbr < 0)
	{
		nbr *= -1;
		sighn = 1;
	}
	i = 0;
	base = 1;
	while (nbr >= base)
	{
		base *= 10;
		i++;
	}
	return (set_number(nbr, sighn, i, base / 10));
}
