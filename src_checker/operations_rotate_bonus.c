/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:51:25 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/04 14:51:25 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return ;
	head = *stack;
	tail = ft_lstlast(*stack);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
}

void	ra(t_list **stack_a, t_list **stack_b)
{
	(void) stack_b;
	rotate(stack_a);
}

void	rb(t_list **stack_a, t_list **stack_b)
{
	(void) stack_a;
	rotate(stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
