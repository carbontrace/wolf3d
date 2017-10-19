/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 09:19:05 by cterrill          #+#    #+#             */
/*   Updated: 2017/04/19 09:21:27 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*tail;
	t_list	*curr;

	head = NULL;
	while (lst)
	{
		tail = f(lst);
		if (!head)
		{
			head = tail;
			curr = tail;
		}
		else
		{
			curr->next = tail;
			curr = curr->next;
		}
		lst = lst->next;
	}
	return (head);
}
