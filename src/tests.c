/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:49:04 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/28 19:02:20 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operations_tests(t_list **stack_a, t_list **stack_b)
{
	print_stacks(*stack_a, *stack_b);
/* 	sa(&stack_a, &stack_b);
	print_stack(stack_a);

	sb(&stack_a, &stack_b);
	print_stack(stack_b);

	ss(&stack_a, &stack_b);
	print_stack(stack_a);

 	content = pop(&stack_a);
	ft_printf("Pop: %d\n", content->value);
	print_stack(stack_a);

	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);

	ra(&stack_a, &stack_b);
	rb(&stack_a, &stack_b);
	rr(&stack_a, &stack_b);
*/
	rra(stack_a, stack_b);
	print_stacks(*stack_a, *stack_b);
	pb(stack_a, stack_b);
	print_stacks(*stack_a, *stack_b);
}