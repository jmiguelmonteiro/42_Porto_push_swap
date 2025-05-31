/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:36:15 by josemigu          #+#    #+#             */
/*   Updated: 2025/05/31 17:46:15 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	t_data	*content_a;
	t_data	*content_b;

	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			content_a = (t_data *)stack_a->content;
			stack_a = stack_a->next;
			ft_printf("%d ", content_a->value);
		}
		else
			ft_printf(". ");
		if (stack_b)
		{
			content_b = (t_data *)stack_b->content;
			stack_b = stack_b->next;
			ft_printf("%d\n", content_b->value);
		}
		else
			ft_printf(".\n");
	}
	ft_printf("- -\na b\n\n");
}

void	print_stack(t_list *stack_a)
{
	t_data	*content_a;

	while (stack_a)
	{
		content_a = (t_data *)stack_a->content;
		ft_printf("i: %d p: %p v: %d t: %p\n", content_a->index, stack_a,
			content_a->value, content_a->target);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
}
