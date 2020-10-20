/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 00:07:07 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/13 05:55:22 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*ret;
	int		l;

	if (!src || start > ft_strlen(src))
	{
		ret = (char*)malloc(sizeof(1));
		*ret = '\0';
		return (ret);
	}
	l = 0;
	if (NULL == (ret = (char*)malloc(len + 1)))
		return (0);
	while (l < (int)(len))
	{
		ret[l] = src[start];
		l++;
		start++;
	}
	ret[l] = '\0';
	return (ret);
}
