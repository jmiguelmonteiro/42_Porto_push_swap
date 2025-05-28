/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:54:10 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/28 22:37:57 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = malloc(sizeof(**stack_a));
	stack_b = malloc(sizeof(**stack_b));
	*stack_a = NULL;
	*stack_b = NULL;
	if (argc < 2)
		return (0);
	check_arguments(argc, argv);
	if (!init_stack(argc, argv, stack_a))
		ft_error();

	if (is_sorted(stack_a))
		ft_printf("Sorted!!!\n");
		
//	operations_tests(stack_a, stack_b);
	
	free_stack(stack_a);
	free_stack(stack_b);
	exit (0);
}
