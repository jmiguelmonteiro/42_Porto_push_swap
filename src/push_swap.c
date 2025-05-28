/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:54:10 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/28 15:30:36 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	check_arguments(argc, argv);
	if (!init_stack(argc, argv, &stack_a))
		ft_error();
	print_stacks(stack_a, stack_b);
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
	rra(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	exit (0);
}
