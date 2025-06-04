/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:51:39 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/04 14:51:39 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}

void	sb(t_list **stack_a, t_list **stack_b)
{
	(void) stack_a;
	swap(stack_b);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
