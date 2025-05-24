/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:54:10 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/24 12:23:41 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_content	*content;

	stack_a = NULL;
	stack_b = NULL;
	
	if (argc < 2)
		return (0);

	check_arguments(argc, argv);
	if (!init_stack(argc, argv, &stack_a))
		ft_error();

	print_stack(stack_a);

/* 	sa(&stack_a, &stack_b);
	print_stack(stack_a);

	sb(&stack_a, &stack_b);
	print_stack(stack_b);

	ss(&stack_a, &stack_b);
	print_stack(stack_a);
 */	
 	content = pop(&stack_a);
	ft_printf("Pop: %d\n", content->value);
	print_stack(stack_a);

	free (content);
 	free_stack(&stack_a);
	free_stack(&stack_b);
	exit (0);
}
