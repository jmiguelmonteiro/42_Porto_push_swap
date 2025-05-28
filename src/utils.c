/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:37:20 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/28 22:34:39 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (0);
}

void	free_node(void *content)
{
	free(content);
}

void	free_stack(t_list **stack)
{
	ft_lstclear(stack, free_node);
}

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_content	*content_a;
	t_content	*content_b;

	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			content_a = (t_content *)stack_a->content;
			stack_a = stack_a->next;
			ft_printf("%d ", content_a->value);
		}
		else
			ft_printf(". ");
		if (stack_b)
		{
			content_b = (t_content *)stack_b->content;
			stack_b = stack_b->next;
			ft_printf("%d\n", content_b->value);
		}
		else
			ft_printf(".\n");
	}
	ft_printf("- -\na b\n\n");
}

t_list	*ft_lstbeforelast(t_list *lst)
{
	t_list	*before_last;

	before_last = NULL;
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		before_last = lst;
		lst = lst->next;
	}
	return (before_last);
}

bool	is_sorted(t_list *stack)
{
	t_list	*head;

	head = stack;
	while (head && head->next)
	{
		if (((t_content *)head->content)->value > ((t_content *)head->next->content)->value)
			return (false);
		head = head->next;
	}
	return (true);
}