/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 02:08:10 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/20 02:19:53 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (lst != NULL && del != NULL)
	{
		if (*lst)
		{
			while (lst[0])
			{
				del(lst[0]->content);
				free(lst[0]);
				lst[0] = lst[0]->next;
			}
		}
	}
}
