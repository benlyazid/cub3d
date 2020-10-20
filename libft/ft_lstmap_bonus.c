/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 02:37:53 by kbenlyaz          #+#    #+#             */
/*   Updated: 2019/10/23 06:42:40 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_head;
	t_list	*lst_new;
	t_list	*lst_cont;

	if (!lst || !f || !del)
		return (0);
	lst_head = lst;
	lst_new = ft_lstnew(f(lst_head->content));
	while (lst_head->next != NULL)
	{
		lst_head = lst_head->next;
		if (!(lst_cont = ft_lstnew(f(lst_head->content))))
		{
			ft_lstclear(&lst_new, del);
			return (0);
		}
		ft_lstadd_back(&lst_new, lst_cont);
	}
	return (lst_new);
}
