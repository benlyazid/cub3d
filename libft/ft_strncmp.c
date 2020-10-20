/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:37:17 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/21 08:24:36 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int					res;
	unsigned	char	*c1;
	unsigned	char	*c2;

	res = 0;
	if (n == 0)
		return (0);
	if (*s1 == '\0' || *s2 == '\0' || n == 0)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	while (n > 0 && (*c1 != '\0' || *c2 != '\0'))
	{
		res = *c1 - *c2;
		if (res != 0)
			return (res);
		c1++;
		c2++;
		n--;
	}
	return (res);
}
