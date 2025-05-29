/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_basic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:10:29 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/28 15:31:47 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	push(t_list **stack, t_content *content)
{
	t_list	*node;

	node = ft_lstnew(content);
	if (!node)
	{
		free_node(content);
		return (free_stack(stack), false);
	}
	ft_lstadd_front(stack, node);
	return (true);
}

t_content	*pop(t_list **stack)
{
	t_list		*head;
	t_list		*next;
	t_content	*content;

	if (ft_lstsize(*stack) < 1)
		return (NULL);
	head = *stack;
	next = head->next;
	content = head->content;
	*stack = next;
	ft_lstdelone(head, NULL);
	return (content);
}
