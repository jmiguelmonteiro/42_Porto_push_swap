/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:10:29 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/28 15:32:02 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **stack_a, t_list **stack_b)
{
	(void) stack_a;
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
