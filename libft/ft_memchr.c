/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:59:40 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/10 20:03:43 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	char	*rut;

	rut = (char*)src;
	while (n > 0)
	{
		if (*rut == c)
			return (rut);
		rut++;
		n--;
	}
	return (0);
}
