/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 22:43:17 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/16 18:45:58 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	int		i;
	char	*rest;
	int		size;

	if (!s || !f)
		return (0);
	size = 0;
	while (s[size])
		size++;
	if (NULL == (rest = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (size > i)
	{
		rest[i] = f(i, s[i]);
		i++;
	}
	rest[i] = '\0';
	return (rest);
}
