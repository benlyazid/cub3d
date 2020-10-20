/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:02:07 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/14 17:38:55 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				res;

	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	res = 0;
	while (n > 0)
	{
		res = *a - *b;
		if (res != 0)
			return (res);
		a++;
		b++;
		n--;
	}
	return (res);
}
