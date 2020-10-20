/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:50:29 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/10 19:52:50 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *from, size_t n)
{
	char	*d;
	char	*f;

	d = (char*)dst;
	f = (char*)from;
	if (d == 0 && f == 0)
		return (0);
	while (n > 0)
	{
		*d = *f;
		d++;
		f++;
		n--;
	}
	return (dst);
}
