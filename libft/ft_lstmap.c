/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 02:30:59 by adremzhy          #+#    #+#             */
/*   Updated: 2026/09/06 02:31:00 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_add(t_list **head, t_list **last, t_list *new_node)
{
	if (*head == NULL)
	{
		*head = new_node;
		*last = new_node;
	}
	else
	{
		(*last)->next = new_node;
		*last = new_node;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*last;
	t_list	*new_node;

	head = NULL;
	last = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_add(&head, &last, new_node);
		lst = lst->next;
	}
	return (head);
}
