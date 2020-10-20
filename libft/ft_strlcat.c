/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:16:38 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/14 19:43:36 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t maxlen)
{
	int		srclen;
	int		dstlen;
	size_t	res;
	int		i;
	int		sheeck;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	sheeck = 0;
	i = 0;
	if ((int)dstlen > (int)maxlen)
		res = (srclen + maxlen);
	else
		res = dstlen + srclen;
	while (src[i] != '\0' && (int)dstlen < ((int)maxlen - 1))
	{
		dst[dstlen] = src[i];
		dstlen++;
		i++;
		sheeck = 1;
	}
	if (sheeck == 1)
		dst[dstlen] = '\0';
	return (res);
}
