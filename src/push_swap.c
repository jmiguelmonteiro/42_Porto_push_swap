/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:54:10 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/28 22:47:55 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	check_arguments(argc, argv);
	if (!init_stack(argc, argv, &stack_a))
		ft_error();
	print_stack(stack_a);
	if (!is_stack_sorted(stack_a))
		sort_stack(&stack_a);
	free_stack(&stack_a);
	exit (0);
}
