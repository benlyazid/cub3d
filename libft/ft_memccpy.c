/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:53:27 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/15 16:37:12 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned	char	*sc;
	unsigned	char	*sd;
	int					i;
	unsigned	char	ch;

	sc = (unsigned char*)src;
	sd = dst;
	i = 0;
	ch = c;
	while (i < (int)n)
	{
		*sd = *sc;
		if (*sc == ch)
			return (sd + 1);
		sc++;
		sd++;
		i++;
	}
	return (0);
}
