/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:55:55 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/14 11:04:03 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;
	int		chlen;

	s = (char*)src;
	d = dst;
	i = 0;
	chlen = len;
	if (s == 0 && d == 0)
		return (0);
	if (s < d)
		while (chlen--)
			*(d + chlen) = *(s + chlen);
	if (s > d)
		ft_memcpy(dst, src, chlen);
	return (d);
}
