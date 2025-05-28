/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:10:29 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/28 12:42:45 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;

	ft_putendl_fd("pa", 1);
	if (ft_lstsize(*stack_b) < 1)
		return ;
	head_a = *stack_a;
	head_b = *stack_b;
	*stack_b = head_b->next;
	head_b->next = head_a;
	*stack_a = head_b;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*head_b;

	ft_putendl_fd("pb", 1);
	if (ft_lstsize(*stack_a) < 1)
		return ;
	head_b = *stack_b;
	head_a = *stack_a;
	*stack_a = head_a->next;
	head_a->next = head_b;
	*stack_b = head_a;
}
