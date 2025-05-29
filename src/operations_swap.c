/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:10:29 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/28 15:31:25 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;

	if (ft_lstsize(*stack) < 2)
		return ;
	head = *stack;
	next = head->next;
	head->next = next->next;
	next->next = head;
	*stack = next;
}

void	sa(t_list **stack_a, t_list **stack_b)
{
	(void) stack_b;
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_list **stack_a, t_list **stack_b)
{
	(void) stack_a;
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}
