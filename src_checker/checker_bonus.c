/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:49:58 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/04 14:49:58 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

bool	is_stack_sorted(t_list *stack)
{
	t_list	*head;

	head = stack;
	while (head && head->next)
	{
		if (((t_data *)head->content)->value
			> ((t_data *)head->next->content)->value)
			return (false);
		head = head->next;
	}
	return (true);
}

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
	get_input(&stack_a, &stack_b);
	if (is_stack_sorted(stack_a) && ft_lstsize(stack_b) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	exit (0);
}
