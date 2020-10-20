/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 05:13:59 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/21 21:57:13 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		index_start(char *str, char c, int position)
{
	int	i;
	int number;

	i = -1;
	number = 0;
	while (str[++i])
	{
		if (position == 1 && str[i] != c)
			return (i);
		if (position != 1 && str[0] != c && str[i] == c &&
				str[i + 1] != c && str[i + 1] != '\0')
		{
			number++;
			if (number + 1 == position)
				return (i + 1);
		}
		if (position != 1 && str[0] == c && str[i] == c &&
				str[i + 1] != c && str[i + 1] != '\0')
		{
			number++;
			if (number == position)
				return (i + 1);
		}
	}
	return (0);
}

int		index_end(char *str, char c, int position)
{
	int	i;
	int number;

	i = 1;
	number = 0;
	while (str[i])
	{
		if ((str[i] == '\0' || str[i] == c) && str[i - 1] != c)
		{
			number++;
			if (number == position)
				return (i);
		}
		i++;
	}
	return (i);
}

int		texte_size(char *str, char c)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
		{
			number++;
		}
		i++;
	}
	return (number);
}

char	*settext(char *str, char *rtn, int start, int end)
{
	int i;

	i = 0;
	while (i < end - start)
	{
		rtn[i] = str[start + i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

char	**ft_split(char const *str, char c)
{
	int		number_of_words;
	char	**rtn_string;
	int		i;
	int		start;
	int		end;

	start = 0;
	end = 0;
	if (!str)
		return (0);
	number_of_words = texte_size((char*)str, c);
	if (NULL == (rtn_string = malloc(sizeof(char*) * (number_of_words + 1))))
		return (0);
	i = 0;
	while (i < number_of_words)
	{
		start = index_start((char*)str, c, i + 1);
		end = index_end((char*)str, c, i + 1);
		if (NULL == (rtn_string[i] = malloc(sizeof(char) * (end - start + 1))))
			return (free_tab(rtn_string, i));
		rtn_string[i] = settext((char*)str, rtn_string[i], start, end);
		i++;
	}
	rtn_string[i] = 0;
	return (rtn_string);
}
