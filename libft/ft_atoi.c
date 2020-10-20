/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:40:51 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/21 09:09:02 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	sheckmax_min(long rtn, int sgn)
{
	if (rtn * sgn > 2147483647)
		return (-1);
	if (rtn * sgn < -2147483648)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	size_t	rtn;
	int		sgn;
	int		fx;

	if (*str == 0)
		return (0);
	rtn = 0;
	sgn = 1;
	fx = 10;
	while (*str <= 19 || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sgn = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		rtn = (rtn * fx) + (*str - '0');
		str++;
		if (sheckmax_min(rtn, sgn) != 1)
			return (sheckmax_min(rtn, sgn));
	}
	return (rtn * sgn);
}
