/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:36:15 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/01 12:52:11 by josemigu         ###   ########.fr       */
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
		ft_printf("i: %d ", content_a->index);
		ft_printf("p: %p ", stack_a);
		ft_printf("v: %d ", content_a->value);
		ft_printf("t: %p ", content_a->target);
		ft_printf("op: %d ", content_a->op);
		ft_printf("n_a: %d ", content_a->n_a);
		ft_printf("n_b: %d ", content_a->n_b);
		ft_printf("cost: %d ", content_a->cost);
		ft_printf("w: %d ", content_a->winner);
		ft_printf("\n");
		stack_a = stack_a->next;
	}
	ft_printf("\n");
}
