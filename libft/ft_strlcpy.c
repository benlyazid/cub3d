/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:13:17 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/21 06:05:09 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t maxlen)
{
	size_t	srclen;
	int		i;

	srclen = ft_strlen(src);
	i = 0;
	if ((int)maxlen != 0)
	{
		while (maxlen - 1 > 0 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
			maxlen--;
		}
		dst[i] = ('\0');
	}
	return (srclen);
}
