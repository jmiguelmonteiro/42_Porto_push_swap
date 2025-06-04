/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:51:12 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/04 14:51:12 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;
	t_list	*before_tail;

	if (ft_lstsize(*stack) < 2)
		return ;
	head = *stack;
	tail = ft_lstlast(*stack);
	before_tail = ft_lstbeforelast(*stack);
	*stack = tail;
	tail->next = head;
	before_tail->next = NULL;
}

void	rra(t_list **stack_a, t_list **stack_b)
{
	(void) stack_b;
	reverse_rotate(stack_a);
}

void	rrb(t_list **stack_a, t_list **stack_b)
{
	(void) stack_a;
	reverse_rotate(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
