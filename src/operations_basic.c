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

bool	push(t_list **stack, t_data *content)
{
	t_list	*node;

	node = ft_lstnew(content);
	if (!node)
	{
		free(content);
		return (free_stack(stack), false);
	}
	ft_lstadd_front(stack, node);
	return (true);
}

t_data	*pop(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	t_data	*content;

	if (ft_lstsize(*stack) < 1)
		return (NULL);
	head = *stack;
	next = head->next;
	content = head->content;
	*stack = next;
	ft_lstdelone(head, NULL);
	return (content);
}

t_data	*peek(t_list *stack)
{
	if (ft_lstsize(stack) < 1)
		return (NULL);
	return (stack->content);
}

t_list	*stack_max_value(t_list *lst)
{
	int		max_value;
	t_list	*max_ptr;

	if (ft_lstsize(lst) < 1)
		return (NULL);
	max_value = ((t_data *)lst->content)->value;
	max_ptr = lst;
	while (lst)
	{
		if (max_value < ((t_data *)lst->content)->value)
		{
			max_value = ((t_data *)lst->content)->value;
			max_ptr = lst;
		}
		lst = lst->next;
	}
	return (max_ptr);
}

t_list	*stack_min_value(t_list *lst)
{
	int		min_value;
	t_list	*min_ptr;

	if (ft_lstsize(lst) < 1)
		return (NULL);
	min_value = ((t_data *)lst->content)->value;
	min_ptr = lst;
	while (lst)
	{
		if (min_value > ((t_data *)lst->content)->value)
		{
			min_value = ((t_data *)lst->content)->value;
			min_ptr = lst;
		}
		lst = lst->next;
	}
	return (min_ptr);
}
